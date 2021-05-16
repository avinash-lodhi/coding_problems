/*Given two singly linked lists, determine if the two lists intersect.
  Return the intersectiong node. Note that the intersection is defined
  based on reference, not value.
*/

#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int k);
};

Node :: Node(int k){
    data = k;
    next = NULL;
}

void insert(Node* &head, int data){
    Node *n = new Node(data);
    if (head == NULL){
        head = n;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void print(Node *head){
    while(head!=NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int listLen(Node *lst){
    int size = 0;
    while(lst!=NULL){
        size++;
        lst = lst->next;
    }
    return size;
}

Node *intercetion(Node *list1, Node* list2){
    Node *small = list1;
    Node *big = list2;
    int len1 = listLen(list1);
    int len2 = listLen(list2);
    int diff = len2-len1;
    if (len1>len2){
        small = list2;
        big = list1;
        diff = len1-len2;
    }
    for(int i=0;i<diff;i++){
        big = big->next;

    }
    while(big!=NULL){
        if(big==small){
            return big;
        }
        big = big->next;
        small = small->next;
    }
    return NULL;
}

int main(){
    Node *list1 = NULL;
    Node *list2 = NULL;
    insert(list1,1);
    insert(list1,2);
    insert(list1,3);
    insert(list1,4);
    insert(list1,5);
    insert(list1,6);
    insert(list1,7);
    insert(list1,8);
    insert(list2,9);
    insert(list2,10);
    //list2->next->next = list1->next->next->next->next->next;
    print(list1);
    print(list2);
    Node *res = intercetion(list1,list2);
    if(res!=NULL){
        cout << "List intersecting at Node -> " << res->data << endl;
    }
    else{
        cout << "Both lists are not intersecting" << endl;
    }
    return 0;
}