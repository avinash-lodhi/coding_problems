#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> a){
//print the given vector
    if (a.empty()){
        return;
    }
    for (auto i = a.begin(); i != a.end(); i++){
        cout << *i << " ";
    }
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

void weave(vector<int> a, vector<int> b, vector<int> prefix){
    /*This function prints the combination of vector a 
      and b such that the respective order of vectors
      a and b is preserved. For example: if a contains
      integer 1,2 and b contains integer 3,4 then
      the function will generate, all possible combinations
      of aUb, such that 1 will alway come before 2,
      and 3 will always come before 4*/
    //base case
    if (a.empty() || b.empty()){
        print_vector(prefix);
        print_vector(b);
        print_vector(a);
        cout << endl;
        return;
    }
    add_to_prefix(a, prefix);
    weave(a,b,prefix);
    /*The value is added back again, so
      that we can recurse properly on b,
      and not lose the initial values of a.
      It also helps in removing duplicate results,
      due to empty value at a.
    */
    add_back(a,prefix);
    add_to_prefix(b,prefix);
    weave(a,b,prefix);
    return;
}

int main(){
    vector <int> a,b,prefix;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    b.push_back(4);
    b.push_back(5);
    b.push_back(6);
    weave(a,b,prefix);
    return 0;
}