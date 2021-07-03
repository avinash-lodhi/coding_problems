/* Paths with sum
Problem Description: Give a binary tree in which each node contains a integer
    value(which might be positive or negative). Design an algorithm to count
    the number of paths that sum to a given value. The path does not need to
    start or end at root or a leaf but it must go downwards
*/
#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

void result_vector(vector<int> v, vector<int>& result_sums, int data, int &num_paths, int given_sum){
    vector <int> result_v;
    for(int i =0; i< v.size(); i++){
        int sum = data + v[i];
        if (sum == given_sum){
            num_paths+=1;
        }
        result_sums.push_back(sum);
    }
}

vector<int> paths_with_sum(TreeNode *root, int &num_paths,int given_sum){
    if(root == NULL){
        vector<int> null_path;
        return null_path;
    }
    vector<int> left_sums, right_sums, result_sums;
    left_sums = paths_with_sum(root->left,num_paths,given_sum);
    right_sums = paths_with_sum(root->right,num_paths,given_sum);
    result_vector(left_sums,result_sums,root->data,num_paths,given_sum);
    result_vector(right_sums,result_sums,root->data,num_paths,given_sum);
    result_sums.push_back(root->data);
    return result_sums;
}


int paths_with_sum(TreeNode* root,int given_sum){
    int num_paths = 0;
    paths_with_sum(root, num_paths, given_sum);
    return num_paths;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    TreeNode *temp = root->left;
    temp->left = new TreeNode(-1);
    temp->right = new TreeNode(6);
    temp = root->right;
    temp->left = new TreeNode(-2);
    temp->right = new TreeNode(-3);
    temp=temp->right;
    temp->left = new TreeNode(5);
    temp->right = new TreeNode(1);
    temp = temp->right;
    temp->left = new TreeNode(1);
    cout << paths_with_sum(root,2) << endl;
    return 0;
}