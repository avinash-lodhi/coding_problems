/*
An animal shelter, which holds only dogs and cats, operates on a
strictly *first in, first out* basis. People must  adopt either the 
"oldest" (based on arrival time) of all animals at athe shelter, or
they can select whether they would prefer a dog or a cat(and will receive the 
oldest of that type). They cannot select which specific animal they would like.
Create the data structures to maintain this system and implement operations such
as enqueue, dequeueuAny, dequeueDog, and dequeueCat
*/

#include<iostream>

using namespace std;

class Node{
public:
    bool data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

class AnimalShelter{
private:
    Node *start;
    Node *end;

    int dequeue(Node* &tmp){
        if(tmp == NULL){return -1;}
        bool d = tmp->data;
        if(tmp->next==NULL){
            tmp = tmp->next;
            return d;
        }
        Node *n = tmp->next;
        tmp->data = n->data;
        tmp->next = n->next;
        return d;
    }
    int dequeue(bool data){
        if (start==NULL){return -1;}
        if ( data==start->data ){
            return dequeue(start);
        }
        Node *temp = start;
        while(temp!=NULL){
            if(data==temp->data){
                return dequeue(temp);
            }
            temp=temp->next;
        }
        return -1;
    }
public:
    AnimalShelter(){
        start=NULL;
        end=NULL;
    }
    void enqueue(bool data){
        Node *n = new Node(data);
        if(start==NULL){
            start = n;
            end = n;
        }
        else{
            end->next = n;
            end=n;
        }
    }
    void display(){
        Node *temp = start;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }
    void dequeueAny(){
        int res = dequeue(start);
        if (res == 1){
            cout << "Congractulations!!! You have adopted a Cat." << endl;
        }
        else if (res == 0){
            cout << "Congractulations!!! You have adopted a Dog." << endl;
        }
        else{
            cout << "Sorry. There are no animals left." << endl;
        }
    }
    
    void dequeueCat(){
        int res = dequeue(true);
        if(res==-1){
            cout << "Sorry. There are no Cat left." << endl;
            return;
        }
        cout << "Congractulations!!! You have adopted a Cat." << endl;
    }

    void dequeueDog(){
        int res = dequeue(false);
        if(res==-1){
            cout << "Sorry. There are no Dog left." << endl;
            return;
        }
        cout << "Congractulations!!! You have adopted a Dog." << endl;
    }

};

int main(){
    AnimalShelter *as = new AnimalShelter();
    as->display();
    as->dequeueAny();
    as->dequeueCat();
    as->dequeueDog();
    as->enqueue(true);
    as->dequeueDog();
    as->enqueue(false);
    as->display();
    as->dequeueAny();
    as->dequeueCat();
    as->dequeueDog();
    as->enqueue(true);
    as->enqueue(true);
    as->enqueue(true);
    as->enqueue(false);
    as->enqueue(true);
    as->enqueue(false);
    as->enqueue(false);
    as->enqueue(false);
    as->display();
    as->dequeueAny();
    as->display();
    as->dequeueDog();
    as->display();
    as->dequeueDog();
    as->display();
    as->dequeueCat();
    as->display();
    as->dequeueAny();
    as->display();
    as->dequeueAny();
    as->display();
    as->dequeueCat();
    as->display();
    as->dequeueAny();
    as->display();
    as->dequeueCat();
    as->display();
    as->dequeueDog();
    as->display();
    return 0;
}