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

Node *kthtolast(Node* head, int k, int &i){
    /* Implementation using recursion, takes O(N) space
       Time complexity is O(N)
       N is number of elements in linklist
    */

    // base condition
    if (head == NULL){
        return NULL;
    }
    // recursively go to the last element, then increament i for each stack call
    Node * temp = kthtolast(head->next,k,i);
    // Note: i will keep increasing as we passed it by reference
    i++;
    //Return kth element
    if(i==k){
        return head;
    }
    return temp;
}

Node *kthtolast(Node *head, int k){
    int i=0;
    return kthtolast(head,k,i);  
}

Node *lastkthNode(Node *head, int k){
    /*  Implementation using iteration, advantage is that it doesn't take O(N) space
        Time complexity is O(N)
        N is number of elements in linklist */

    // Implementation using two pointers    
    Node *kptr = head;
    for (int i=0;i<k;i++){
        if(kptr == NULL && i!=k-1){return NULL;}
        kptr = kptr->next;
    }

    while(kptr!=NULL){
        kptr = kptr->next;
        head = head->next;
    }
    return head;
}
int main(){
    Node *head = NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    insert_at_tail(head,7);
    insert_at_tail(head,8);
    Node *ans = kthtolast(head,9);
    Node *ans2 = kthtolast(head,9);
    if (ans != NULL){
    cout << ans->data << endl;
    cout << ans2->data << endl;
    }
    return 0;
}