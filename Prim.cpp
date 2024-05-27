#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int u;

struct Edge{
    int begin, end;
};

class Graph{
    private:
        int a[100][100], check[100], dinhTree[100], soCanhTree, soDinhTree, n, dH;
        Edge Tree[100];
    public:
        void readdata();
        void Prim(int u);
};

void Graph :: readdata(){
    cin >> n >> u;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
}

void Graph :: Prim(int u){
    dH = 0;
    soDinhTree = 0;
    soCanhTree = 0;
    memset(check, 0, sizeof(check));
    memset(dinhTree, 0, sizeof(dinhTree));
    dinhTree[++soDinhTree] = u;
    check[u] = 1;
    while(soCanhTree < n - 1){
        int tmp, tmpBegin, tmpEnd;
        int min = 1e9;
        for(int i = 1 ; i <= soDinhTree; i++){
            tmp = dinhTree[i];
            for(int j = 1; j <= n; j++){
                if(a[tmp][j] && !check[j] && a[tmp][j] < min){
                    min = a[tmp][j];
                    tmpBegin = tmp;
                    tmpEnd = j;
                }
            }
        }
        dH+= min;
        Tree[++soCanhTree].begin = tmpBegin;
        Tree[soCanhTree].end = tmpEnd;
        dinhTree[++soDinhTree] = tmpEnd;
        check[tmpEnd] = 1;
        sort(dinhTree + 1, dinhTree + 1 + soDinhTree);
    }
    cout << "dH = " << dH << endl;
    for(int i = 1; i <= soCanhTree; i++){
        cout << min(Tree[i].begin, Tree[i].end) << " " << max(Tree[i].begin, Tree[i].end) << endl;
    }
}

int main(){
    Graph G;
    G.readdata();
    G.Prim(u);
}