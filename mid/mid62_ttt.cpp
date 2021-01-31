#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3010;

vector<int> adj[MAX_N];
int deg[MAX_N];
int n,m,bipartite;
list<pair<int,int>> keep;
bool err[MAX_N];

void read_input(){
    int x,y;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        keep.emplace_back(x,y);
        deg[x]++;
        deg[y]++;
    }
}

bool discovered[MAX_N];
int mark[MAX_N];

void init_BFS(){
    bipartite = 1;
    for (int i=0; i<MAX_N; i++){
        discovered[i] = false;
        err[i] = false;
        mark[i] = 0;
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
            if (err[U]==true && err[v]==true){
                continue;
            }
            if (!discovered[v]){
                Q.push(v);
                discovered[v] = true;
                mark[v] = (mark[U]==0) ? 1:0;
            }
            else if (discovered[v] && (mark[U]==mark[v])){
                bipartite = 0;
                break;
            }
        }
    }
}

int main(){
    read_input();
    for (auto i=keep.begin(); i!=keep.end(); i++){
        init_BFS();
        err[i->first] = true;
        err[i->second] = true;
        for (int j=0; j<n; j++){
            bfs(j);
        }
        if (bipartite){
            cout << i->first+1 << " " << i->second+1;
            break;
        }
    }
    return 0;
}
