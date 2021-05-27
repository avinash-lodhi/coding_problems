#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "TreeNode.h"

class Node
{
public:
    TreeNode* tn;
    Node *next;
    Node(TreeNode* d);
};

Node::Node(TreeNode* d)
{
    tn = d;
    next = NULL;
}
#endif