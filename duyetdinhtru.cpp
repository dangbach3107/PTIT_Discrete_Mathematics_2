#include <bits/stdc++.h>
using namespace std;

int a[100][100], check[100], n;

void DFS(int u){
    check[u] = 1;
    for(int v = 1; v <= n; v ++){
        if(a[u][v] && !check[v]){
            DFS(v);
        }
    }
}

int sum(int c[]){
    int s = 0;
    for(int i = 0; i <= 99; i++){
        s += c[i];
    }
    return s;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];
    for(int u = 1; u <= n; u++){
        check[u] = 1;
        if(u == 1){
            DFS(2);
            if(sum(check) != n) cout << u << " ";
        }
        else{
            DFS(1);
            if(sum(check) != n) cout << u << " ";
        }
        memset(check, 0, sizeof(check));
    }
}