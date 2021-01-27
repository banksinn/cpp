#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100010;

int n,m;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        deg[i] = 0;
    }
    for (int i=0; i<m; i++){
        int u,v;
        cin >> u >> v; //undirected graph
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
}

bool discovered[MAX_N];
int layer[MAX_N];

void init(){
    for (int i=0; i<n; i++){
        discovered[i] = false;
    }
}

void bfs(int s){
    discovered[s] = true;
    int lnum = 0;
    list<int> current_layer;
    list<int> next_layer;
    current_layer.push_back(s);
    while (!current_layer.empty()){
        for (auto i=current_layer.begin(); i!=current_layer.end(); i++){
            int U = *i;
            //cout << U << " " << layer[U] << endl;
            for (int d=0; d<deg[U]; d++){
                int v = adj[U][d];
                if (!discovered[v]){
                    next_layer.push_back(v);
                    discovered[v] = true;
                    layer[v] = layer[U] + 1;
                }
            }
        }
        current_layer = next_layer;
        next_layer.clear();
    }
}

int main(){
    int count=0;
    read_input();
    init();
    for (int s=0; s<n; s++){
        if (!discovered[s]){
            count++;
            bfs(s);
        }
    }
    cout << count;
    return 0;
}
