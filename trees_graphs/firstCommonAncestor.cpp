#include <iostream>
#include "TreeNode.h"

using namespace std;

bool decendent(TreeNode *q, TreeNode *p){
    //fuction to tell if node p in decendent of node q
    if (q==NULL) return false;
    if(q->left == p || q->right == p) return true;
    return decendent(q->left,p)|| decendent(q->right,p);
}

TreeNode *firstAncestor(TreeNode *a, TreeNode *p, TreeNode *q){
    //function to return the first common ancenstor
    if(a==NULL) return NULL;
    if(a==p || a==q) return a;
    TreeNode *left_branch = firstAncestor(a->left,p,q);
    if (left_branch!=NULL && left_branch!=p && left_branch!=q) return left_branch;
    TreeNode *right_branch = firstAncestor(a->right,p,q);
    if(left_branch!=NULL && right_branch!=NULL) return a;
    if(left_branch==NULL && right_branch==NULL) return NULL;
    return left_branch!=NULL ? left_branch:right_branch;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    TreeNode *temp = root->left;
    temp->left = new TreeNode(4);
    temp = temp->left;
    temp->right = new TreeNode(5);
    TreeNode *p = temp->right;
    temp->left = new TreeNode(6);
    TreeNode *q = temp->left;
    temp = root->right;
    temp->left = new TreeNode(7);
    temp->right = new TreeNode(8);
    temp = temp->right;
    temp->right = new TreeNode(9);
    temp = temp->right;
    temp->right = new TreeNode(0);
    //cout << decendent(root->left,temp)<<endl;
    TreeNode *a = firstAncestor(root, p, q);
    if (a!=NULL) cout << a->data << endl;
    return 0;
}
