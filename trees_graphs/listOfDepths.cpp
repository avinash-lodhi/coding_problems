#include <iostream>
#include "Queue.h"
#include "TreeNode.h"

using namespace std;

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    TreeNode *temp = root->left;
    temp->left = new TreeNode(4);
    temp->right = new TreeNode(5);
    temp = root->right;
    temp->left = new TreeNode(6);
    temp = root->left->right;
    temp->right = new TreeNode(7);
    temp = root->left->left;
    temp->left = new TreeNode(8);


    Queue *q = new Queue();
    q->enqueue(root);
    while(!q->isEmpty()){
        q->display();
        Queue *nq = new Queue();
        TreeNode *pn = q->dequeue();
        while (pn!=NULL){
            nq->enqueue(pn->left);
            nq->enqueue(pn->right);
            pn = q->dequeue();
        }
        q = nq;
    }
    return 0;
}