/* Problem Description: Write a method to return all subsets of a set */

#include<iostream>
#include<vector>

using namespace std;
void print_vector(vector<int> x){
    //method to print a vector
    cout << "{";
    for(int i=0;i<x.size();i++){
        cout << " " << x[i] << " ";
    }
    cout << "}";
    cout << endl;
}

void powerSet(vector<int>& s, vector<vector<int>> &subsets){
    /* method to generate all the subsets of a set recursively */

    //base case: if set is empty append empty vector to subsets
    if (s.size()==0){
        vector<int> x;
        subsets.push_back(x);
        return;
    }
    //recursive case: take last element and call the function again
    int ele = s[s.size()-1]; 
    s.pop_back();
    powerSet(s,subsets);
    int size = subsets.size();
    //loop through the existing subsets and append new subsets by adding the 
    //taken out last element to the existing subsets.
    for (int i =0; i<size; i++){
        vector<int> temp;
        temp = subsets[i];
        temp.push_back(ele);
        subsets.push_back(temp);
    }
    return;
}

vector<vector<int>> powerSet(vector<int> s){
    //method to take only set as input and return all subsets
    vector<vector<int>> subsets;
    powerSet(s,subsets);
    return subsets;
}

int main(){
    vector<int> tc1;
    tc1.push_back(1);
    tc1.push_back(2);
    tc1.push_back(3);
    tc1.push_back(4);
    cout << "Input vector: ";
    print_vector(tc1);
    vector<vector<int>> rs1;
    rs1 = powerSet(tc1);
    cout << "All Subsets: " << endl;
    for(int i=0;i<rs1.size();i++){
        print_vector(rs1[i]);
    }
    return 0;
}