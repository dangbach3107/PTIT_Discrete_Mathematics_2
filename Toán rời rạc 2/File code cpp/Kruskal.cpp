#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge{
    int begin, end, weight;
};

class Graph{
    private:
        int n, a[100][100], T[100][100], check[100], soCanh, soCanhTree, dH;
        Edge arr[100], arrT[100];
    public:
        void readdata();
        void init();
        void reinit();
        void T_DFS(int u);
        void Kruskal();
        
};

void Graph :: readdata(){
    cin >> n;
    soCanh = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] && i < j){
                soCanh++;
                arr[soCanh].begin = i; arr[soCanh].end = j; arr[soCanh].weight = a[i][j];
            }
        }
    }
}

void Graph :: init(){
    memset(check, 0, sizeof(check));
    memset(T, 0, sizeof(T));
}

void Graph :: reinit(){
    memset(check, 0 , sizeof(check));
}

void Graph :: T_DFS(int u){
    check[u] = 1;
    for(int v = 1; v <= n; v++){
        if(!check[v] && T[u][v]) T_DFS(v);
    }
}

bool cmp(Edge a, Edge b){
    if(a.weight == b.weight) return a.begin < b.begin;
    else return a.weight < b.weight;
}

void Graph :: Kruskal(){
    soCanhTree = 0;
    dH = 0;
    init();
    sort(arr + 1, arr + 1 + soCanh, cmp);
    for(int i = 1; i <= soCanh; i++){
        reinit();
        T_DFS(arr[i].begin);
        if(!check[arr[i].end]){
            soCanhTree++;
            arrT[soCanhTree].begin = arr[i].begin;
            arrT[soCanhTree].end = arr[i].end;
            T[arr[i].begin][arr[i].end] = T[arr[i].end][arr[i].begin] = 1;
            dH += arr[i].weight;
        }
    }
    cout << "dH = " << dH << endl;
    for(int i = 1 ;i <= soCanhTree; i++){
        cout << arrT[i].begin << " " << arrT[i].end << endl;
    }
}

int main(){
    Graph g;
    g.readdata();
    g.Kruskal();
}

