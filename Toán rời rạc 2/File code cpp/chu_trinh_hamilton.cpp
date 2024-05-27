#include <iostream>

using namespace std;

int n, k, u , a[105][105];
int res[100]; 
bool check[100];
void in(){
    for(int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << res[1] << endl;
}
void hmt(int k){
    for(int y = 1; y <= n; y++){
        if(a[res[k - 1]][y]){
            if(k == n + 1 && y == res[1]){
                in();
                return;
            }
            else if(!check[y]){
                res[k] = y;
                check[y] = 1;
                hmt(k + 1);
                check[y] = 0;
            }
        }
    }
}
int main(){
    cin >> n >> u;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];
    res[1] = u;
    check[u] = 1;
    hmt(2);
}