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
    private:
        Node *top = NULL;
        int minm = 2147483647;
    public:
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
                cout << temp->data << "->";
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
            return NULL;
        }

        int pop(){
            if(!isEmpty()){
                int data = top->data;
                top = top->next;
                return data;
            }
            return NULL;
        }
        
        int min(){
            if(isEmpty) return NULL;
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
}