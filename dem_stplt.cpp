#include <iostream>
using namespace std;

int a[100][100], check[100], n, dem;

void DFS(int u){
    check[u] = 1;
    for(int v = 1; v <= n; v++){
        if(a[u][v] && !check[v]){
            DFS(v);
        }
    }
}

int main(){
    dem = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];
    for(int u = 1; u <= n; u++){
        if(!check[u]){
            dem++;
            DFS(u);
        }
    }
    cout << dem;
}