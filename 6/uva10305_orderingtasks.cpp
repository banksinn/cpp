#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;

vector<int> adj[MAX_N];
int deg[MAX_N];
int n,m;

void init_input(){
    for (int i=0; i<MAX_N; i++){
        adj[i].clear();
        deg[i] = 0;
    }
}

void read_input(){
    int x,y;
    for (int i=0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        deg[x]++;
    }
}

bool visited[MAX_N];

void init_DFS(){
    for (int i=0; i<MAX_N; i++){
        visited[i] = false;
    }
}

stack<int> topo_order;

void dfs(int U){
    visited[U] = true;
    for (int d=0; d<deg[U]; d++){
        int v = adj[U][d];
        if (!visited[v]){
            dfs(v);
        }
    }
    topo_order.push(U);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    while (!(n==0 && m==0)){
        init_input();
        read_input();
        init_DFS();
        for (int i=0; i<n; i++){
            if (!visited[i]){
                dfs(i);
            }
        }
        while (!topo_order.empty()){
            cout << topo_order.top()+1 << " ";
            topo_order.pop();
        }
        cout << "\n";
        cin >> n >> m;
    }
    return 0;
}
