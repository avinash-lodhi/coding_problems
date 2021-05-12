#include <iostream>
#include <string>

using namespace std;

int main(){
    int count = 1;
    string long_str;
    cout << "Enter a string to compress"<< endl;
    cin >> long_str;
    string compressed_str = "";
    char point = long_str[0];
    for (int i =1; i<long_str.length(); i++){
        if (point != long_str[i]){
            compressed_str = compressed_str +point+ to_string(count);
            point = long_str[i];
            count = 1;
        }
        else{
            count ++;
        }
    }
    compressed_str = compressed_str +point+ to_string(count);
    if(compressed_str.length() < long_str.length()){
        cout << compressed_str << endl;
    }
    else{
        cout << long_str << endl;
    }
    return 0;
}