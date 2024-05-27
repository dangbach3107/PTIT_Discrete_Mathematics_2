#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int n; cin >> n;
    int u; cin >> u;
    vector <vector <int>> g (n + 1, vector<int> (n + 1, 0));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j++){
            cin >> g[i][j];
        }
    }
    stack <int> st;
    st.push(u);
    vector <int> ce;
    while(!st.empty()){
        int s = st.top();
        int t = -1;
        for(int i = n; i >= 1; i--){
            if(g[s][i]) t = i;
        }
        if(t != -1){
            st.push(t);
            g[s][t] = g[t][s] = 0;
        }
        else{
            st.pop();
            ce.push_back(s);
        }
    }
    for(int i = ce.size() - 1; i>= 0; i--){
        cout << ce[i] << " ";
    }
}