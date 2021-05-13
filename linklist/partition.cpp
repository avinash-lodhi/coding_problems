#include<iostream>

using namespace std;

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

void insert(Node* &head,int data){
//fuction to insert the node at tail
Node *n = new Node(data);
if (head==NULL){head=n;}
else {
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    }
}
//function to print the singly link list
void print(Node* head){while(head!=NULL){cout<<head->data<<"->"; head=head->next;}cout<<"NULL"<<endl;}

void partition(Node* &head, int partition){
    /*
    Function to partition the link list at given partition,
    this function takes O(N) space, where N is size of link list
    and takes O(N) time
    */
   if(head == NULL){return;}
   Node *lesser = NULL;
   Node *bigger = NULL;
   Node *temp = head;
   while(temp!=NULL){
       if(temp->data < partition){insert(lesser,temp->data);}
       else{insert(bigger,temp->data);}
       temp=temp->next;
   }
   temp = lesser;
   while(temp->next!=NULL){temp=temp->next;}
   temp->next=bigger;
   head=lesser;
}

void partitionInPlace(Node* head,int partition){
    /*
    Function to partition the link list at given partition,
    this function take O(1) space and O(N) time
    */
   Node *current = head;
   Node *runner;
   while(current->next!=NULL){
       runner = current->next;
       if(current->data >= partition){
           while(runner!=NULL){
               if(runner->data < partition){
                   int temp = current->data;
                   current->data = runner->data;
                   runner-> data = temp;
                   break;
               }
               runner=runner->next;
           }
       }
       current = current->next;
   }
}

int main(){
    Node *head = NULL;
    insert(head,3);
    insert(head,5);
    insert(head,8);
    insert(head,5);
    insert(head,10);
    insert(head,2);
    insert(head,1);
    print(head);
    //partition(head,5);
    partitionInPlace(head,5);
    print(head);
    return 0;
}