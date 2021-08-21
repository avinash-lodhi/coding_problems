/*Problem Description: Write a method to compute all permutation
                       of a string with unique characters
*/

#include<iostream>
#include<string>

using namespace std;

void printPermutations(string s, string prefix, string dup){
    //base case
    if (s.empty()){
        cout << prefix << dup << endl;
        return;
    }
    int size = s.size();
    string::iterator it;
    for (int i=size-1;i>=0;--i){
        char x = s[i];
        it = prefix.end()-1;
        if(*it == x){
            dup.push_back(x);
        }
        else{
        prefix.push_back(x);
        string temp = s;
        temp.erase(i,1);
        printPermutations(temp,prefix,dup);
        prefix.pop_back();
        }
    }
}

int main(){
    printPermutations("aaaa","","");
}