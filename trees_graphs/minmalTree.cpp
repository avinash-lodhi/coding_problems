/*
Given a sorted(increasing order) array with unique integer,
write an algorithm to create a binary search tree with minimal height
*/
#include<iostream>

using namespace std;

class minmalTree
{
public:
    int data;
    minmalTree* left;
    minmalTree *right;
    minmalTree(int d);
};

minmalTree::minmalTree(int d)
{
    data = d;
    left = NULL;
    right = NULL;
}

minmalTree* makeBST(int *arr, int size){
    if (size<=0){
        return NULL;
    }
    int mid_index = (size+1)/2 - 1;
    minmalTree *root = new minmalTree(*(arr+mid_index));
    root->left = makeBST(arr,mid_index);
    root->right = makeBST(arr+mid_index+1,size-mid_index-1);
    return root;
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    minmalTree *root = makeBST(arr,6);
    cout << root->data << endl;
    cout << root->left->data << "\t";
    cout << root->right->data << endl;
    cout << root->left->left << "\t";
    cout << root->left->right->data << "\t";
    cout << root->right->left->data << "\t";
    cout << root->right->right->data << endl;
    return 0;
}