/*
You have two numbers represented by a linked list, where each node contains a
single digit. The digits are stored in reverse order, such that the 1's digit
is at the head of the list. Write  function that adds the tow numbers and 
returns the sum as a linked list. 
*/
#include <iostream>

using namespace std;

//Node class to represent a single node of a singly integer link list
class Node
{
public:
    int data;
    Node *next;
    Node(int k);
};
//Constructor
Node::Node(int k)
{
    data = k;
    next = NULL;
}

//insert data at end
void insert(Node* &head,int data){
    Node* n = new Node(data);
    if(head == NULL){head = n; return;}
    Node *temp = head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->next = n;
    return;
}

//print the link list
void print(Node *head){
    while(head!=NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

//Function to get the length of the linklist
int length(Node *head){
    int len = 0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

//Fuction to make same length for both n1 and n2 lists 
void makeSameLength(Node *n1, Node* n2){
    int len1= length(n1);
    int len2= length(n2);
    int diff;
    Node *big;
    Node *small; 
    if (len1>=len2){
        big=n1;
        small=n2;
        diff= len1-len2;
    }
    else{
        big = n2;
        small = n1;
        diff = len2-len1;
    }
    for(int i=0;i<diff;i++){
        insert(small,0);
    }
}

//Function to add two lists
void sumlist(Node *n1, Node *n2, int d){
    int sum = n1->data + n2->data + d;
    n1->data = sum % 10;
    d = sum/10;
    if(n1->next == NULL){
        if(d>0){ insert(n1,d); }
        return;
    }
    sumlist(n1->next,n2->next,d);
}

//Function to add two lists
void sumlist(Node *n1, Node *n2){
    int d = 0;
    makeSameLength(n1,n2);
    sumlist(n1,n2,d);
}

//Create a linklist given int num
Node * createList(int num){
    Node *head = NULL;
    while(num!=0){
        insert(head,num%10);
        num = num/10;
    }
    return head;
}

int main(){
    int num1;
    int num2;
    cout << "Enter first Number" << endl;
    cin >> num1;
    cout << "Enter second Number" << endl;
    cin >> num2;
    Node *list1 = createList(num1);
    Node *list2 = createList(num2);
    print(list1);
    print(list2);
    sumlist(list1,list2);
    cout << "The resultant link list is: ";
    print(list1);
    return 0;
}