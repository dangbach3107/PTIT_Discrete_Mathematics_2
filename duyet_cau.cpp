#include<iostream>
#include <stack>
#include<cstring>

using namespace std;

int a[100][100], check[100], n;

void DFS(int u){
    check[u] = 1;
    stack <int> s;
    s.push(u);
    while(!s.empty()){
        int tmp = s.top();
        s.pop();
        for(int v= 1;  v <= n; v++){
            if(!check[v] && a[tmp][v]){
                check[v] = 1;
                s.push(tmp);
                s.push(v);
                break;
            }
        }
    }
}

int sum(){
    int d = 0;
    for(int i = 1; i <= 99; i++) d+= check[i];
    return d;
}

int main(){
    cin >> n;
    for(int i = 1; i <=n ; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];
    for(int i = 1; i <n ; i++){
        for(int j = i + 1; j <= n; j++){
            memset(check, 0, sizeof(check));
            if(a[i][j]){
                a[i][j] = 0; a[j][i] = 0;
                DFS(1);
                if(sum() != n) cout << i << " " << j << endl;
                a[i][j] = 1; a[j][i] = 1;
            }
        }
    }
}