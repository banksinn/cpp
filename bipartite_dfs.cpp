#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100100;

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
    cout << "Input number of node: ";
    cin >> n;
    cout << "Input number of line: ";
    cin >> m;
    for (int i=0; i<m; i++){
        cout << "line: ";
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
}

bool visited[MAX_N];
int color[MAX_N];

void init_DFS(){
    for (int i=0; i<MAX_N; i++){
        visited[i] = false;
        color[i] = 0;
    }
}

int ans;

void dfs_bipartite(int U, int c){
    if (visited[U]){
        if (color[U]!=c){
            ans = 1;
        }
        return;
    }
    visited[U] = true;
    color[U] = c;
    for (int d=0; d<deg[U]; d++){
        int v = adj[U][d];
        if (c==1){
            dfs_bipartite(v,0);
        }
        else{
            dfs_bipartite(v,1);
        }
    }
}

int main(){
    int t;
    cout << "Bipartite(undirected)!!\n";
    cout << "Enter number of test: ";
    cin >> t;
    while (t--){
        ans = 0;
        init_input();
        init_DFS();
        read_input();
        dfs_bipartite(0,0);
        if (ans){
            cout << "This is not bipartite.\n";
        }
        else{
            cout << "This is bipartite.\n";
        }
    }
    return 0;
}
