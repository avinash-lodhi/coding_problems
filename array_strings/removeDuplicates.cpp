#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

vector<int> remove_duplicates(int *a, int size){
    vector<int> unique_entry;
    unordered_map<int,bool> seen;
    for(int i=0; i<size; i++){
        if(seen.count(a[i])>0){
            continue;
        }
        seen[a[i]]=true;
        unique_entry.push_back(a[i]);
    }
    return unique_entry;
}

int main(){
    int a[]={1,6,3,7,2,3,1,8,5,6,4};
    int size = 11;
    vector <int> nvc = remove_duplicates(a,size);
    vector <int>::iterator it = nvc.begin();
    while(it!=nvc.end()){
        cout << *it << " ";
        it ++;
    }
    return 0;
}