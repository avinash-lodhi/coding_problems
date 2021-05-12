#include <iostream>
#include <string>

using namespace std;

void replace_space(int i, string &str, int size){
    int index = size+i*2;
    for (int idx=size-1; idx>=0; idx--){
        if (str[idx] == ' '){
            str[index-1]='0';
            str[index-2]='2';
            str[index-3]='%';
            index = index-3;
        }
        else{
        str[index-1] = str[idx];
        index --;
        }
    }

}
int main(){
    string str = "Mr John Smith    ";
    int size = 13;
    int space_count = 0;
    for(int i=0;i<size;i++){
        if(str[i] == ' '){
            space_count++;
        }
    }
    replace_space(space_count,str,size);
    cout << str << endl;
}
