#include <iostream>
#include <string>

using namespace std;

bool oneEditAway(string &s1, string &s2){
    bool flag = false;
    int idx;
    for (int i=0;i<s2.length();i++){
        if (flag and s1.length()!= s2.length()){idx = i+1;} else {idx=i;}
        if (s1[idx]!=s2[i]){
            if (!flag) flag = true; else return false;
        }
    }
    return true;
}

int main(){
    string str1, str2;
    cout << "Enter first string"<<endl;
    cin >> str1;
    cout << "Enter second string" << endl;
    cin >> str2;
    if (str1.length() == str2.length()) cout << oneEditAway(str1, str2) << endl;
    else if (str1.length() == str2.length()-1) cout << oneEditAway(str1,str2) << endl;
    else if (str1.length() == str2.length()+1) cout << oneEditAway(str2,str1) << endl;
    else cout << false << endl;
    return 0;
}