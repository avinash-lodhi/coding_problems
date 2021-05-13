/* Implement an algorithm to delete a node in the middle
   (i.e any node but first and last node, not necessarily the exact middle)
   of a singly link list, given only access to that node.
*/

#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insert_at_tail(Node* &head, int data){
    Node* n = new Node(data);
    if (head == NULL){
        head = n;
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next=n;

}

void print_link_list(Node *head){
    while(head != NULL){
        cout << head->data<<" -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void deleteNode(Node *k){
    //Funtion to remove element k, given only access to k
    if(k!=NULL && k->next != NULL){
        k->data = k->next->data;
        k->next = k->next->next;
    }
}
int main(){
    Node *head = NULL;
    for(int i=0;i<10;i++){ insert_at_tail(head,i);}
    Node *temp = head;
    print_link_list(head);
    deleteNode(temp->next);
    print_link_list(head);
    temp=temp->next;
    deleteNode(temp->next);
    print_link_list(head);
    return 0;
}