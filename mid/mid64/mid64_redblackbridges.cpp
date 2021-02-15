#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 300010;

vector<int> adj1[MAX_N],adj2[MAX_N];
int deg1[MAX_N],deg2[MAX_N];
int n,m,s,t;

void read_input(){
    int a,b,c;
    cin >> n >> m >> s >> t;
    s--; t--;
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        a--; b--;
        if (c==0 || c==1){
            adj1[a].push_back(b);
            adj1[b].push_back(a);
            deg1[a]++;
            deg1[b]++;
        }
        if (c==0 || c==2){
            adj2[a].push_back(b);
            adj2[b].push_back(a);
            deg2[a]++;
            deg2[b]++;
        }
    }
}

bool discovered[MAX_N];
int layer[MAX_N];

void init_BFS(){
    for (int i=0; i<MAX_N; i++){
        discovered[i] = false;
        layer[i] = 0;
    }
}

int bfs(int s, vector<int> adj[], int deg[]){
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
            if (v==t){
                return layer[v];
            }
        }
    }
}

int main(){
    int ans1,ans2,check1=0,check2=0;
    read_input();
    init_BFS();
    ans1 = bfs(s,adj1,deg1);
    if (discovered[s] && discovered[t]){
        check1 = 1;
    }
    init_BFS();
    ans2 = bfs(s,adj2,deg2);
    if (discovered[s] && discovered[t]){
        check2 = 1;
    }
    if (check1==1 || check2==1){
        if (ans1<=ans2){
            cout << ans1;
        }
        else{
            cout << ans2;
        }
    }
    else{
        cout << -1;
    }
    return 0;
}
