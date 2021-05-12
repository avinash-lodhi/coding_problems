#include <iostream>
#include <string>

using namespace std;
const int MAX_CHAR = 128;

bool unique_char(string &str){
    if (str.length() > 128 ) return false;
    bool char_count[MAX_CHAR] = {false};
    for(int i=0; i<str.length(); i++){
        if (char_count[str[i]]){
            return false;
        }
        char_count[str[i]] = true;
    }
    return true;
}
int main(){
    string s;
    cin >> s;
    if (unique_char(s)){
        cout << "String is unique" << endl;
    }
    else{
        cout << "String is not unique" << endl;
    }
}