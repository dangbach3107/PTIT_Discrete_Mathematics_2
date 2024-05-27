#include <iostream>
using namespace std;

int a[100][100], truoc[100], n, s, d[100], check[100];

int size(){
    int dem = 0;
    for(int i = 1; i <= n; i++) dem += check[i];
    return dem;
}

void Dijkstra (int s){
    for(int i = 1; i <= n; i++) d[i] = 1e9;
    d[s] = 0;
    check[s] = 1;
    for(int v = 1; v <= n; v++){
        if(!check[v] && a[s][v]){
            d[v] = a[s][v];
            truoc[v] = s;
        }
    }
    while(size() != n){
        int tmp = 1e9, u = -1;
        for(int z = 1; z <= n; z++){
            if(!check[z]){
                if(tmp > d[z]){
                    u = z;
                    tmp = d[z];
                }
            }
        }
        if(u == -1) break;
        d[u] = tmp;
        check[u] = 1;
        for(int v = 1; v <= n; v++){
            if(!check[v] && a[u][v]){
                if(d[v] > d[u] + a[u][v]){
                    d[v] = d[u] + a[u][v];
                    truoc[v] = u;
                }
            }
        }
    }
}

int main(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    Dijkstra(s);
    for(int i = 1; i <= n; i++){
        if(i == s){
            cout << "K/c " << s << " -> " << i << " = " <<  0 << " ; " << s << " <- " << s << endl;
        }
        else if(d[i] == 1e9){
                cout << "K/c " << s << " -> " << i << " = " << "INF; \n";
        }
        else{
            cout << "K/c " << s << " -> " << i << " = " <<  d[i] << " ; ";
            int tmp = i;
            while(tmp != s){
                cout << tmp << " <- ";
                tmp = truoc[tmp];
            }
            cout << s ;
            cout << endl;
        }
    }
}