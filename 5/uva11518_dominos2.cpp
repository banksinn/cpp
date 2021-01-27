#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10010;

vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input(int m){
    int x,y;
    for (int i=0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        deg[x]++;
    }
}

bool discovered[MAX_N];
int layer[MAX_N];

void init_BFS(){
    for (int i=0; i<MAX_N; i++){
        discovered[i] = false;
        adj[i].clear();
        deg[i] = 0;
    }
}

void bfs(int s){
    discovered[s] = true;
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
                layer[v] = layer[U] + 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,l,z;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n >> m >> l;
        init_BFS();
        read_input(m);
        for (int j=0; j<l; j++){
            cin >> z;
            z--;
            if (!discovered[z]){
                bfs(z);
            }
        }
        int ans = 0;
        for (int j=0; j<n; j++){
            if (discovered[j]){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
