/* Problem Definition: A binary search tree was created by traversing 
 through an array from left to right and inserting each element.
 Give a binary search tree with distinct element, 
 print all possible arrays that could have led to this tree. */

#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

void print_vector(vector<int> a){
//print the given vector
    if (a.empty()){
        return;
    }
    for (auto i = a.begin(); i != a.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
}

void add_to_prefix(vector<int> &v, vector<int> &prefix){
    //Function to take value from the begining of the vector and push it in the back of prefix
    int data = v[0];
    prefix.push_back(data);
    v.erase(v.begin());
    return;
}

void add_back(vector<int> &v, vector<int> &prefix){
    //Function to take value from the prefix end and insert it in the begining of the vector
    int data = prefix[prefix.size()-1];
    prefix.pop_back();
    v.insert(v.begin(),data);
    return;
}

void weave(vector<int> a, vector<int> b, vector<int> prefix, vector<vector<int>>& weaved_results){
    /*This function prints the combination of vector a 
      and b such that the respective order of vectors
      a and b is preserved. For example: if a contains
      integer 1,2 and b contains integer 3,4 then
      the function will generate, all possible combinations
      of aUb, such that 1 will alway come before 2,
      and 3 will always come before 4*/
    //base case
    if (a.empty() || b.empty()){
        vector<int> weaved = prefix;
        weaved.insert(weaved.end(),a.begin(),a.end());
        weaved.insert(weaved.end(),b.begin(),b.end());
        weaved_results.push_back(weaved);
        return;
    }
    add_to_prefix(a, prefix);
    weave(a,b,prefix,weaved_results);
    /*The value is added back again, so
      that we can recurse properly on b,
      and not lose the initial values of a.
      It also helps in removing duplicate results,
      due to empty value at a.
    */
    add_back(a,prefix);
    add_to_prefix(b,prefix);
    weave(a,b,prefix,weaved_results);
    return;
}
vector<vector<int>> weave(vector<int> a, vector<int> b){
    //Function to weave two vectors and return a vector of int vectors
    vector<vector<int>> results;
    vector<int> prefix;
    weave(a,b,prefix,results);
    return results;

}

void print_vector_v(vector<vector<int>> v){
    // Function to print vector of vector;
    for(int i=0; i < v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> generate_all_sequences(TreeNode *root){
    //base case 
    //1. return empty vector<vector<int>> if node is null
    if (root == NULL){
        vector<vector<int>> results;
        return results;
    }
    //2. if node is leaf node enter its value in vector of vector and return
    if(root->left == NULL && root->right == NULL){
        vector<vector<int>> results;
        vector<int> result;
        result.push_back(root->data);
        results.push_back(result);
        return results;
    }

    vector<vector<int>> all_left_sequences, all_right_sequences, results;
    
    //generate all left and right sequences
    all_left_sequences = generate_all_sequences(root->left);
    all_right_sequences = generate_all_sequences(root->right);

    //if any of the branch is empty assign results to non empty branch
    if (all_left_sequences.empty()||all_right_sequences.empty()){
        results = all_left_sequences.empty() ? all_right_sequences : all_left_sequences;
    }

    // Weave left and right sequences
    for(int i = 0; i < all_left_sequences.size(); i++){
        for(int j = 0; j < all_right_sequences.size(); j++){
            vector<vector<int>> w_res;
            w_res = weave(all_left_sequences[i],all_right_sequences[j]);
            results.insert(results.end(),w_res.begin(),w_res.end());
        }
    }

    // add root in the start of every sequence
    for(int i=0; i < results.size(); i++){
        results[i].insert(results[i].begin(),root->data);
    }
    return results;
}

int main(){
    vector<vector<int>> results;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    results = generate_all_sequences(root);
    cout << "Size: " << results.size() << endl;
    for(int i=0; i < results.size(); i++){
        for(int j=0; j<results[i].size(); j++){
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}