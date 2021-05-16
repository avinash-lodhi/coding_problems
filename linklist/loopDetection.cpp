/* Given a circular linked list, 
implement an algorithm that returns the node at the beginning of the loop */

#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node (int k);
};

Node:: Node(int k){
    data = k;
    next = NULL;
}
void insert(Node* &head, int data){
    Node* n = new Node(data);
    if(head == NULL){
        head = n;
        return;
    }
    Node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
}

void print(Node *head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* isCircular(Node *head){
    Node *slow = head;
    Node *fast = head;
    bool circular = false;
    while (slow!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        //if fast and slow pointer meet means there is loop
        if(slow == fast){
            circular = true;
            break;
        }
    }
    
    if (circular){
        //At this point fast pointer is k step behind the beginning of loop,
        //and head is also k step behind the begining of loop
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
    return NULL;
}

int main(){
    Node *head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head,7);
    insert(head,8);
    insert(head,9);
    Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = head->next->next->next->next;
    Node* circular_node = isCircular(head);
    if(circular_node!=NULL){
        cout << circular_node->data << endl;
    }
    else{
        cout << "Not a circular linklist";
    }
    return 0;
}