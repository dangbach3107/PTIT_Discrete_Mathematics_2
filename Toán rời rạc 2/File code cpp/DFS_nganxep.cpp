#include <iostream>
using namespace std;

int a[100][100], check[100], n;

void DFS(int u){
    check[u] = 1;
    cout << u << " ";
    for(int v = 1; v <= n; v++){
        if(a[u][v] && !check[v]) DFS(v);
    }
    
}

int main(){
    cin >> n;
    for(int i = 1; i <=n ; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    DFS(1);
}