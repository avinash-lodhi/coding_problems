#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Node.h"

class Queue
{
private:
    Node *start;
    Node *end;
public:
    Queue();
    void display();
    void enqueue(TreeNode *temp);
    TreeNode* dequeue();
    bool isEmpty();
};

Queue::Queue()
{
    start = NULL;
    end = NULL;
}

void Queue::display(){
    Node *temp = start;
    while(temp!=NULL){
        std::cout << temp->tn->data << "->";
        temp=temp->next;
    }
    std::cout<<"NULL"<<std::endl;
}

void Queue::enqueue(TreeNode *temp){
    if (temp == NULL) {return;}
    Node* n = new Node(temp);
    if(start == NULL){
        start = n;
        end = n;
        return;
    }
    end->next = n;
    end = n;
    return;
}

TreeNode* Queue::dequeue(){
    if(start==NULL){
        return NULL;
    }
    TreeNode* rv= start->tn;
    start = start->next;
    return rv;
}

bool Queue::isEmpty(){
    return start == NULL;
}

#endif