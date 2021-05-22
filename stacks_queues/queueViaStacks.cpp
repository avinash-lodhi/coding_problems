/*
Implement a MyQueue class which implements a queue using two stacks
*/
#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

class Stack{
private:
    Node *top;
public:
    Stack(){
        top = NULL;
    }
    void push(int d){
        Node *n = new Node(d);
        Node *tmp = top;
        top = n;
        top->next = tmp;
    }
    void display(){
        Node *tmp = top;
        while(tmp!=NULL){
            cout << tmp->data << "->";
        }
        cout << "NULL" << endl;
    }
    int peek(){
        if(isEmpty()){return -1;}
        return top->data;
    }
    bool isEmpty(){
        return top == NULL;
    }
    int pop(){
        if(isEmpty()){return -1;}
        Node *tmp = top;
        top = top->next;
        return tmp->data;
    }
};

class MyQueue{
private:
    Stack *stk1;
    Stack *stk2;
    void fillStack(){
        int data;
        if(stk2->isEmpty()){
            data = stk1->pop();
            while(data!=-1){
                stk2->push(data);
                data = stk1->pop();
            }
        }
    }
public:
    MyQueue(){
        stk1=new Stack();
        stk2=new Stack();
    }
    void enqueue(int data){
        stk1->push(data);
    }
    int dequeue(){
        fillStack();
        return stk2->pop();
    }
};

int main(){
    MyQueue *q = new MyQueue();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->enqueue(6);
    q->enqueue(7);
    q->enqueue(8);
    q->enqueue(9);
    q->enqueue(10);
    int data = q->dequeue();
    q->enqueue(11);
    while(data!=-1){
        cout << data << "->";
        data = q->dequeue();
    }
    cout << "NULL" << endl;
    return 0;
}