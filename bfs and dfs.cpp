#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100010;

int n,m;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input(){
    cout << "Input number of edge: ";
    cin >> n;
    cout << "Input number of adjacent: ";
    cin >> m;
    for (int i=0; i<n; i++){
        deg[i] = 0;
    }
    for (int i=0; i<m; i++){
        int u,v;
        cout << "Input edge to edge (edge edge): ";
        cin >> u >> v; //directed graph
        u--; v--;
        adj[u].push_back(v);
        //adj[v].push_back(u);
        deg[u]++;
        //deg[v]++;
    }
}

bool visited[MAX_N];

void init_DFS(){
    for (int i=0; i<MAX_N; i++){
        visited[i] = false;
    }
}

void dfs(int U){
    visited[U] = true;
    cout << U+1 << " ";
    for (int d=0; d<deg[U]; d++){
        int v = adj[U][d];
        if (!visited[v]){
            dfs(v);
        }
    }
}

bool discovered[MAX_N];
int layer[MAX_N];

void init_BFS(){
    for (int i=0; i<MAX_N; i++){
        discovered[i] = false;
    }
}

void bfs(int s){
    discovered[s] = true;
    cout << s+1 << " ";
    layer[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()){
        int U = Q.front();
        Q.pop();
        for (int d=0; d<deg[U]; d++){
            int v = adj[U][d];
            if (!discovered[v]){
                Q.push(v);
                discovered[v] = true;
                cout << v+1 << " ";
                layer[v] = layer[U] + 1;
            }
        }
    }
}

int main(){
    read_input();
    init_DFS();
    init_BFS();
    for (int s=0; s<n; s++){
        if (s==0){
            cout << "DFS: ";
        }
        if (!visited[s]){
            dfs(s);
        }
    }
    cout << "\n";
    for (int s=0; s<n; s++){
        if (s==0){
            cout << "BFS: ";
        }
        if (!discovered[s]){
            bfs(s);
        }
    }
    return 0;
}
