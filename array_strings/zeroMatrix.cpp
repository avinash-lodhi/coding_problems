#include<iostream>

using namespace std;

int main(){
    int a[3][3] = {{0,0,3},{4,5,6},{7,8,9}};
    int n =3;
    int count =0;
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i =0; i<n;i++){
        for(int j=0; j<n;j++){
            if (a[i][j]==0){
                count ++;
                if(i==0 && j==0){
                    temp=-2;
                }
                else if(i==0){
                    a[0][0]=-1;
                    a[0][j]=0;
                }
                else{
                    a[i][0]=0;
                    a[0][j]=0;
                }
            }
        }
    }
    a[0][0] = temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    if (count > 0){
        for (int i =n-1; i>=0; i--){
            for(int j =n-1;j>=0;j--){
                if(a[i][0]<0){
                    if(a[0][0]<-1){a[0][j]=0;a[j][0]=0;}
                    else{a[0][j]=0;}
                }
                if(a[i][0]==0){a[i][j]=0;}
                if(a[0][i]==0){a[j][i]=0;}
                // for(int k=0;k<n;k++){
                //     for(int l=0;l<n;l++){
                //         cout << a[k][l] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
            }
            continue;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
