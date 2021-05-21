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
public:
    MyQueue(){
        stk1=new Stack();
        stk2=new Stack();
    }
    void enqueue(int data){
        stk1->push(data);
    }
    bool isEmpty(){
        return stk1->isEmpty();
    }
    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        int data = stk1->pop();
        while(data!=-1){
            stk2->push(data);
            data=stk1->pop();
        }

    }
};