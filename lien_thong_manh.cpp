#include <bits/stdc++.h>

using namespace std;

int a[100][100], check[100], truoc[100], n;

int DFS(int u){
    int d = 0;
    check[u] = 1;
    for(int v = 1; v <= n; v++){
        if(a[u][v] && !check[v]){
            DFS(v);
            d++;
        }
    }
    return d;
}

bool ktra(){
    for(int u = 1; u <= n; u++){
        if(DFS(u) != n) return 0;
        else memset(check, 0, sizeof(check));
    }
    return 1;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) for(int j = 1; j <=n ;j++) cin >> a[i][j];
    if(ktra()){
        cout << "strongly connected";
    }else cout << "not strongly connected";
}