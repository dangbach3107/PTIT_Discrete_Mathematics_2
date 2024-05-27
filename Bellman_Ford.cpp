#include <iostream>
using namespace std;

int n, s, a[100][100], d[100], truoc[100];

void bellman_ford(int s){
    for(int v = 1; v <= n; v++){
        d[v] = a[s][v];
        truoc[v] = s;
    }
    for(int k = 1; k <= n - 2; k++){
        for(int v = 1; v <= n; v++){
            for(int u = 1; u <= n ; u++){
                if(d[v] > d[u] + a[u][v] ){
                    d[v] = d[u] + a[u][v];
                    truoc[v] = u;
                }
            }
        }
    }
}

void in(){
    for(int i = 1; i <= n; i++){
        if(i != s){
            cout << "K/c " << s << " -> " << i << " = " ;
            if(d[i] > 1e8)cout << "INF;\n";
            else{
                cout << d[i] << "; ";
                int tmp = i;
                while(tmp != s){
                    cout << tmp << " <- ";
                    tmp = truoc[tmp];
                }
                cout << s << endl;
            }
        }
        else{
            cout << "K/c " << s << " -> " << i << " = 0 " ;
            cout << s << " <- " << i << endl;
        }
    }
}

int main(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) a[i][j] = 1e9;
        }
    bellman_ford(s);
    in();
}

