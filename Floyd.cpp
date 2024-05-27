#include <iostream>
using namespace std;

int a[100][100], n, d[100][100], Next[100][100];
void Floyd(){
    //buoc 1: khoi tao
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++){
            d[i][j] = a[i][j];
            if(d[i][j] != 1e9) Next[i][j] = j;
            else Next[i][j] = 0;
        }
    //buoc 2: lap
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){ 
            for(int j = 1; j <= n; j++) {
                if((d[i][k] != 1e9 && d[k][j] != 1e9) && d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){ 
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(i != j && a[i][j] == 0) 
                a[i][j] = 1e9;
        }
    }
    Floyd();
    for(int i = 1; i <= n; i++){
        for(int v = 1; v <= n; v++){
            cout << "K/c " << i << "-> " << v << " = " << d[i][v] << "; " ;
            int u = i;
            while(u != v){
                cout << u << "--> ";
                u = Next[u][v];
            }
            cout << u << endl;
        }
        cout << endl << endl;
    }
}