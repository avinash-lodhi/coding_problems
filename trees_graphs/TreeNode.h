#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>

class TreeNode
{
public:
    int data;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int d);
};

TreeNode::TreeNode(int d)
{
    data = d;
    left = NULL;
    right = NULL;
}

#endif