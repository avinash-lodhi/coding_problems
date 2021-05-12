#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    unordered_map<string, int> ourmap;
    pair<string,int> p("abc",1);
    ourmap.insert(p);
    cout << "abc = " << ourmap["abc"] << endl;
    ourmap["def"] = 2;
    ourmap["abc"] = 3;
    cout << "def = " << ourmap["def"] << endl;
    cout << "abc = " << ourmap["abc"] << endl;
    cout << "Value coming for 'ghi' because of [] " << ourmap["ghi"] << endl;
    cout << "Value from the at function, remember it throws exception if key is not present -> " << ourmap.at("ghi") << endl;
    //using count function
    if (ourmap.count("x")>0){
        cout << "Key x is present" << endl;
    }
    else {
        cout << "Key x is not present"<< endl;
    }
    //size function
    cout << "Size before deletion -> " << ourmap.size() << endl;
    // erase
    if (ourmap.count("ghi")>0){
        ourmap.erase("ghi");
    }
    cout << "Size after deletion -> " << ourmap.size() << endl;

    //iterator
    unordered_map <string, int> :: iterator it = ourmap.begin();
    while (it != ourmap.end()){
        cout << "Key => " << it->first << ", Value => " << it->second << endl;
        it++;
    }
}