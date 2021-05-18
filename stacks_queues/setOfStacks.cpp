/*
Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the provious stack exceeds some threshold.
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

class StackNode{
    public:
        Stack *stk;
        StackNode *next;
        StackNode(Stack* &k){
            stk = k;
            next = NULL;
        }
};

class SetOfStacks{
private:
    StackNode *top;
    int size;
    int tsd;
public:
    SetOfStacks(int t){
        top = NULL;
        size = 0;
        tsd = t;
    }

    void push(int data){
        if(size%tsd == 0){
            Stack *k = new Stack();
            StackNode *n = new StackNode(k);
            n->next = top;
            top = n;
        }
        top->stk->push(data);
        size = (size+1)%tsd;
    }

    bool isEmpty(){
        return (size ==0 && top==NULL);
    }
    void display(){
        StackNode *temp = top;
        while(temp!=NULL){
            temp->stk->display();
            temp=temp->next;
        }
    }
    int peek(){
        if(isEmpty()) return -1;
        return top->stk->peek();
    }

    int pop(){
        if(isEmpty()) return -1;
        if (top->stk->isEmpty()){
            top = top->next;
        }
        if(top == NULL) return -1;
        size = (tsd+size-1)%tsd;
        return top->stk->pop();
    }
};

int main(){
    SetOfStacks *sostk = new SetOfStacks(3);
    sostk->push(1);
    sostk->push(2);
    sostk->push(3);
    sostk->push(4);
    sostk->push(5);
    sostk->push(6);
    sostk->push(7);
    sostk->push(8);
    sostk->push(9);
    sostk->display();
    for (int i=0;i<10;i++){
        cout << sostk->pop()<<endl;
    }
}