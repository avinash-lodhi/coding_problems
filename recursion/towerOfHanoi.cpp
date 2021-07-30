#include<iostream>
#include<stack>

using namespace std;

void printStack(stack<int> s){
    if(s.empty()){
        cout << "empty";
    }
    while(!s.empty()){
        cout << ' ' << s.top();
        s.pop();
    }
    cout<<endl;
}

void TowerofHanoi(stack<int>& start, stack<int>& aux, stack<int>& dest, int size){
    if(start.empty()|| size < 1){
        return;
    }
    if(size==1){
        dest.push(start.top());
        start.pop();
        return;
    }
    TowerofHanoi(start,dest,aux,size-1);
    dest.push(start.top());
    start.pop();
    TowerofHanoi(aux,start,dest,size-1);
}

int main(){
    stack<int> s;
    stack<int> a;
    stack<int> d;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);
    printStack(a);
    printStack(d);
    TowerofHanoi(s,a,d,5);
    printStack(s);
    printStack(a);
    printStack(d);
}
