#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100100;

vector<int> adj[MAX_N];
int deg[MAX_N];
int n,m,ans=0;

void init_input(){
    for (int i=0; i<MAX_N; i++){
        adj[i].clear();
        deg[i] = 0;
    }
}

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

bool discovered[MAX_N];
int mark[MAX_N];

void init_BFS(){
    ans = 0;
    for (int i=0; i<MAX_N; i++){
        discovered[i] = false;
    }
}

void bfs(int s){
    discovered[s] = true;
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
                mark[v] = (mark[U]==0) ? 1:0;
            }
            else if (discovered[v] && (mark[U]==mark[v])){
                ans = 1;
                break;
            }
        }
    }
}

int bipartite(){
    for (int i=0; i<n; i++){
        for (int d=0; d<deg[i]; d++){
            int v = adj[i][d];
            if (mark[i]==mark[v]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    for (int i=0; i<k; i++){
        init_input();
        read_input();
        init_BFS();
        for (int j=0; j<n; j++){
            if (!discovered[j]){
                bfs(j);
            }
        }
        if (ans){
            cout << "no\n";
        }
        else{
            cout << "yes\n";
        }
    }
    return 0;
}
