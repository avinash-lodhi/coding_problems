#include <iostream>

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
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data<<" -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insert_at_head(Node* &head, int data){
    Node* n = new Node(data);
    n->next = head;
    head = n;
}

void removeDuplicate(Node *head){
    int val1,val2;
    while(head != NULL){
        Node *runner = head;
        while(runner->next != NULL){
            if(head->data == runner->next->data){
                runner->next = runner->next->next;
            }
            else{
            runner = runner->next;
            }
        }
        head=head->next;
    }
}

bool search(Node* head, int key){
    Node *temp = head;
    while (temp != NULL){
        if (temp->data == key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
int main(){
    Node *head = NULL;
    print_link_list(head);
    insert_at_head(head,1);
    print_link_list(head);
    insert_at_tail(head,2);
    insert_at_head(head,0);
    insert_at_tail(head,3);
    insert_at_tail(head,3);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    insert_at_tail(head,7);
    insert_at_tail(head,8);
    insert_at_tail(head,3);
    insert_at_tail(head,5);
    insert_at_tail(head,9);
    cout << search(head,5) << endl;
    cout << search(head,3) << endl;
    print_link_list(head);
    removeDuplicate(head);
    print_link_list(head);
    return 0;
}