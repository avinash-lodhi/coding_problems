/*Implement a function to check if a binary is a binary search Tree*/

#include<iostream>

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

bool isBST(TreeNode* root){
    /*Function to check if the given binary tree is BST*/
    //base condition
    if((root==NULL)||(root->left == NULL && root->right == NULL)){
        return true;
    }
    //check for left branch and right branch recursively
    bool left_branch = isBST(root->left);
    bool right_branch = false;
    if (left_branch){
        right_branch = isBST(root->right);
    }
    if (right_branch){
        if(root->left!=NULL && root->right!=NULL){
            return root->left->data <= root->data && root->right->data > root->data;
        }
        if(root->left == NULL){
            return root->right->data > root->data;
        }
        return root->left->data <= root->data;
    }
    return false;
}

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout << isBST(root) << endl;
    return 0;
}