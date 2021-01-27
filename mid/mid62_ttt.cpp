#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3010;

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
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
}

bool visited[MAX_N];
int color[MAX_N];
bool err[MAX_N][MAX_N];

int ans;

void init_DFS(){
    for (int i=0; i<MAX_N; i++){
        visited[i] = false;
        color[i] = 0;
    }
    for (int i=0; i<MAX_N; i++){
        for (int j=0; j<MAX_N; j++){
            err[i][j] = false;
        }
    }
}

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
    int ans_x,ans_y,check=0;
    read_input();
    for (int i=0; i<n; i++){
        for (int d=0; d<deg[i]; d++){
            int node = adj[i][d];
            //cout << "Node: " << node << "\n";
            init_DFS();
            err[i][d] = true;
            for (int j=0; j<deg[node]; j++){
                if (adj[node][j]==i){
                    err[node][j] = true;
                }
            }
            for (int j=0; j<n; j++){
                if (!visited[j]){
                    dfs_bipartite(j,0);
                }
            }
            /*cout << "Mark: ";
            for (int j=0; j<n; j++){
                cout << mark[j] << " ";
            }
            cout << "\nBipartite: " << bipartite(node) << "\n";*/
            if (ans){
                check = 1;
                ans_x = i;
                ans_y = node;
            }
        }
        if (check){
            break;
        }
    }
    cout << ans_x+1 << " " << ans_y+1;
    return 0;
}
