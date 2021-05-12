#include <iostream>
using namespace std;

const int MAX_CHAR=128;

bool check_permutation(int * arr, string str){
    for(int i=0; i<str.length(); i++){
        arr[str[i]]--;
        if (arr[str[i]] < 0) return false;
    }
    return true;
}

void map_array(int *arr, string str){
    for(int i=0; i<str.length(); i++){
        arr[str[i]]++;
    }
    
}

int main(){
    string str1;
    string str2;
    cout << "Enter first string" << endl;
    cin >> str1;
    cout << "Enter second string" << endl;
    cin >> str2;
    int tracker[MAX_CHAR] = {0};
    if (str1.length()!= str2.length()){
        cout << str1 << " is not a permutation of " << str2 << endl;
    }
    map_array(tracker,str1);
    if (check_permutation(tracker,str2)){
        cout << str1 << " is a permutation of " << str2 << endl;
    }
    else{
        cout << str1 << " is not a permutation of " << str2 << endl;
    }

    return 0;
}