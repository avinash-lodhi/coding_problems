/* Implementation of stack using linklist */
#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        int minm;
        Node *next;
        Node (int k,int m){
            data = k;
            minm = m;
            next = NULL;
        }
};

class Stack{
    /*
    For now taking assumption that we are using only positive integers,
    so returning -1 when stak is empty
    TODO: throw exception instead of returning -1.
    */
    private:
        Node *top;
        int minm;
    public:
        Stack(){
            top = NULL;
            minm = 2147483647;
        }
        void push(int data){
            Node *n = new Node(data, minm);
            n->next = top;
            top = n;
            if(top->data < minm){
                minm = top->data;
                top->minm = minm;
            }
        }

        void display(){
            Node *temp = top;
            while(temp!=NULL){
                cout << temp->data << "|" << temp->minm << " -> ";
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
        
        int min(){
            if(isEmpty()) return -1;
            return top->minm;
        }
};

int main(){
    Stack stk;
    stk.push(5);
    stk.push(4);
    stk.push(8);
    stk.push(15);
    stk.push(18);
    stk.push(3);
    stk.push(9);
    stk.display();
    cout << stk.min() << endl;  
    stk.pop();
    stk.pop();
    cout << stk.min() << endl;
}