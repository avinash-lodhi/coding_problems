/*
Write a program to sor a stack such that the smallest items are on the top.
You can use an additional temporary stack, but you may not cpou the elements into 
any other data structure (sucha as an array). The stack supports the follwoing
operations: push,pop,peek,isEmpty.
*/

#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node (int k){
            data = k;
            next = NULL;
        }
};

class Stack{
private:
    Node *top;
public:
    Stack(){
        top = NULL;
    }
    void push(int data){
            Node *n = new Node(data);
            n->next = top;
            top = n;
        }

        void display(){
            Node *temp = top;
            while(temp!=NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }

        bool isEmpty(){
            return top == NULL;
        }

        int peek(){
            if(!isEmpty()){
                return top->data;
            }
            return -1;
        }

        int pop(){
            if(!isEmpty()){
                int data = top->data;
                top = top->next;
                return data;
            }
            return -1;
        }
};
void sort(Stack* &stk){
    Stack *sstk = new Stack();
    while(!stk->isEmpty()){
        int data = stk->pop();
        if(sstk->isEmpty()){sstk->push(data);}
        else{
            int sdata = sstk->peek();
            while(sdata<data && sdata>=0){
                stk->push(sstk->pop());
                sdata = sstk->peek();
            }
            sstk->push(data);
        }
    }
    stk = sstk;
}

int main(){
    Stack *stk = new Stack();
    stk->push(5);
    stk->push(8);
    stk->push(1);
    stk->push(4);
    stk->push(2);
    stk->display();
    sort(stk);
    stk->display();
    return 0;
}