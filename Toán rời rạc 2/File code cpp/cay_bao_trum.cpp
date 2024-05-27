#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, u, a[100][100], check[100];

void Tree_DFS(int u){
    check[u] = 1;
    for(int v = 1; v <= n; v++){
        if(a[u][v] && !check[v]){
            cout << min(u, v) << " " << max(u, v) << endl;
            Tree_DFS(v);
        }
    }
}

void BFS_tree(int u){
    queue <int> q;
    q.push(u);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        check[tmp] = 1;
        for(int v = 1; v <= n; v++){
            if(a[tmp][v] && !check[v]){
                cout << min(tmp, v) << " " << max(tmp, v) << endl;
                check[v] = 1;
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> n;
     cin >> u;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    cout << "DFS tree\n";
    Tree_DFS(u);
    memset(check, 0, sizeof(check));
    cout << "BFS tree\n";
    BFS_tree(u);
}