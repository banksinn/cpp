#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200010;

vector<int> adj[MAX_N];
int deg[MAX_N];
int n,m,k;
int ans = 0;

void read_input(){
    int x,y;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
}

int mark[MAX_N];

void dfs(int a, int b){
    //cout << b << "\n";
    mark[b] = a;
    for (int d=0; d<deg[b]; d++){
        int v = adj[b][d];
        if (!mark[v]){
            dfs(a,v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    read_input();
    for (int i=1; i<n+1; i++){
        if (!mark[i-1]){
            dfs(i,i-1);
        }
        /*for (int j=0; j<n; j++){
            cout << mark[j] << " ";
        }
        cout << "\n";*/
    }
    for (int i=0; i<k; i++){
        cin >> a >> b;
        a--; b--;
        if (mark[a]==mark[b]){
            cout << 1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
    return 0;
}
