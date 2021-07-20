#include<iostream>
#include<set>
#include<iterator>
#include<bits/stdc++.h>
using namespace std;
//TODO: generalize for any rows and colums
bool checkPath(int r, int c, int a[4][5], set<pair<int,int>>& s){
    if(r<0||c<0) return false;
    if(a[r][c]==0) return false;
    if(r==0 && c==0) return true;
    bool up = checkPath(r-1,c,a,s);
    if(up){
        pair p = make_pair(r,c);
        s.insert(p);
        return up;
    }
    bool left = checkPath(r,c-1,a,s);
    if(left){
        pair p = make_pair(r,c);
        s.insert(p);
        return left;
    }
    return false;
}

int main() {
    int a[4][5];
    for(int i=0;i<4;i++){
        for(int j=0; j<5; j++){
            a[i][j] = 1;
        }
    }
    a[0][1] = 0;
    a[1][2] = 0;
    a[2][0] = 0;
    a[2][4] = 0;
    a[3][2] = 0;
    set<pair <int,int> > s;
    cout << checkPath(3,4,a,s) << endl;
    for (auto const &var : s) {
      cout << "(" << var.first << ", "<< var.second << ")"<< " ";
   }
}
