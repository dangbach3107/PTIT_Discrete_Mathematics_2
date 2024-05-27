#include <iostream>
using namespace std;
#include <queue>

int a[100][100], check[100], n;

void BFS(int u){
    queue <int> q;
    cout << u << " ";
    check[u] = 1;
    q.push(u);
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int v = 1; v <= n; v++){
            if(a[s][v] && !check[v]){
                cout << v << " ";
                check[v] = 1;
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i =1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];
    BFS(1);
}