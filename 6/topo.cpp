#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100100;

vector<int> adj[MAX_N];
int deg[MAX_N];
int n,m;

void read_input(){
    int x,y;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        deg[x]++;
    }
}

bool visited[MAX_N],mark[MAX_N];

void init_DFS(){
    for (int i=0; i<MAX_N; i++){
        visited[i] = false;
        mark[i] = false;
    }
}

int cycle = 0;
stack<int> topo_order;

void dfs(int U){
    visited[U] = true;
    for (int d=0; d<deg[U]; d++){
        int v = adj[U][d];
        if (!visited[v]){
            dfs(v);
        }
        if (!mark[v]){
            cycle = 1;
        }
    }
    topo_order.push(U);
    mark[U] = true;
}

int main(){
    read_input();
    init_DFS();
    for (int i=0; i<n; i++){
        if (!visited[i]){
            dfs(i);
        }
    }
    if (cycle){
        cout << "no";
    }
    else{
        while (!topo_order.empty()){
            cout << topo_order.top()+1 << "\n";
            topo_order.pop();
        }
    }
    return 0;
}
