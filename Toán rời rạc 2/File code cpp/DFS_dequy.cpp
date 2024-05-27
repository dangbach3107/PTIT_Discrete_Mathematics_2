#include <bits/stdc++.h>
using namespace std;
#define Max 100

class Dothi{
    int n; 
    int a[Max][Max];
    public: 
    bool chuaxet[Max];
    void readdata();
    void init();
    void DFS(int u);
};

void Dothi::readdata(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}
            
void Dothi::init(){
    for(int i = 1; i <= n; i++){ 
        chuaxet[i] = true;
    }
}
    
void Dothi::DFS(int u){
    cout << u << " ";
    chuaxet[u] = false;
    for(int v = 1; v <= n; v++){
        if(a[u][v] == 1 && chuaxet[v] == true){ 
            DFS(v);
        }
    }
}
        
int main(){
    Dothi G;
    G.readdata();
    G.init();
    G.DFS(1);
}