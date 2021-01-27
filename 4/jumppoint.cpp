#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1010;

vector<int> adj[MAX_N],before_MAX;
int deg[MAX_N];
int x[MAX_N],y[MAX_N];

void read_input(int n, int r){
    for (int i=0; i<n+2; i++){
        for (int j=0; j<n+2; j++){
            if (i==j){
                continue;
            }
            if (pow(abs(x[j]-x[i]),2)+pow(abs(y[j]-y[i]),2)<=r*r){
                adj[i].push_back(j);
                adj[j].push_back(i);
                deg[i]++;
                deg[j]++;
            }
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
    int n,r,a,b;
    cin >> n >> r;
    x[0]=0; y[0]=0;
    for (int i=0; i<n; i++){
        cin >> a >> b;
        x[i+1] = a;
        y[i+1] = b;
    }
    x[n+1]=100; y[n+1]=100;
    read_input(n,r);
    init_BFS();
    bfs(0);
    if (layer[n+1]==0){
        cout << -1;
    }
    else{
        cout << layer[n+1];
    }
    return 0;
}
