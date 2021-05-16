/* Implement a function to check if a linked list is a palindrome.*/
#include<iostream>

using namespace std;

//class Node represent a single node of integer link list
class Node
{
public:
    int data;
    Node *next;
    Node(int k);
};

Node::Node(int k)
{
    data = k;
    next = NULL;
}

//Funtion to insert an element at the end of the list
void insert(Node* &head, int data){
    Node *n = new Node(data);
    if (head == NULL){head=n; return;}
    Node *temp = head;
    while (temp->next != NULL){temp = temp->next;}
    temp->next = n;
    return;
}

//Function to print the linklist
void print(Node *head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

//Funtion to check palindrome
bool isPalindrome(Node* &head,int size, int middle, bool even, int itr){
    int data;
    if(itr < middle){
        data = head->data;
        head = head->next;
        itr ++;
        bool val = isPalindrome(head,size,middle,even,itr);
        if(val){
            head = head->next;
            return data == head->data;
        }
        return false;
    } 
    if (itr == middle){
        if(even){
            data = head->data;
            head = head->next;
            return data == head->data;
        }
        return true;
    }
    return false;
}
//Function to check palindrome
bool isPalindrome(Node *head){
    int itr = 1;
    int size = 0;
    Node *temp = head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    int middle = (size+1)/2;
    bool even = size%2 == 0;
    return isPalindrome(head,size,middle,even,itr);
}

int main(){
    Node *head = NULL;
    insert(head,5);
    insert(head,2);
    insert(head,3);
    insert(head,9);
    insert(head,3);
    insert(head,2);
    insert(head,5);
    print(head);
    if(isPalindrome(head)){cout << "The LinkList is a palindrome" << endl;}
    else {cout << "The LinkList is not a palindrome" << endl;}
}