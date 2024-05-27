#include <bits/stdc++.h>
using namespace std;

int a[100][100], check[100], truoc[100], n;

void DFS(int u){
    check[u] = 1;
    for(int v = 1; v <= n; v++){
        if(a[u][v] && !check[v]){
            truoc[v] = u;
            DFS(v);
        }
    }
}

void BFS(int u){
    check[u] = 1;
    queue <int> q;
    q.push(u);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int v = 1; v <= n; v++){
            if(a[tmp][v] && !check[v]){
                check[v] = 1;
                truoc[v] = tmp;
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> n;
    int s, t; cin >> s >> t;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];
    DFS(s);
    if(!check[t]){ 
        cout << "no path"; 
        return 0;
    }
    cout << "DFS path: ";
    int tmp = t;
    cout << tmp << " ";
    while(tmp != s){
        tmp = truoc[tmp];
        cout << tmp << " ";
    }
    cout << endl;
    memset(check, 0, sizeof(check));
    memset(truoc, 0, sizeof(truoc));
    BFS(s);
    if(!check[t]){ 
        cout << "no path"; 
        return 0;
    }
    cout << "BFS path: ";
    tmp = t;
    cout << tmp << " ";
    while(tmp != s){
        tmp = truoc[tmp];
        cout << tmp << " ";
    }
}