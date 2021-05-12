#include <iostream>

using namespace std;

int main(){
    int image[5][5]={{0,1,1,0,1},{0,0,0,1,0},{0,0,1,0,1},{1,0,0,0,0}};
    int n = 4;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout << image[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i=0;i<=n;i++){
        for(int j=i;j<n-i;j++){
                int temp = image[i][j];
                image[i][j] = image[n-j][i];
                image[n-j][i] = image[n-i][n-j];
                image[n-i][n-j] = image[j][n-i];
                image[j][n-i] = temp;
        }
    }

    cout << "\n";

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout << image[i][j] << " ";
        }
        cout << "\n";
    }
}