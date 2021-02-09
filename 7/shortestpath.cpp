#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100010;

vector<pair<int,int>> adj[MAX_N];
int dis[MAX_N];
int n,m;

void read_input(){
    int x,y,weight;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> x >> y >> weight;
        adj[x].emplace_back(y,weight);
        adj[y].emplace_back(x,weight);
    }
}

void init_dijkstra(){
    for (int i=1; i<MAX_N; i++){
        dis[i] = 10100;
    }
    dis[1] = 0;
}

void dijkstra(int w, int node){
    priority_queue<pair<int,int>> pq;
    pq.emplace(-w,node);
    while (!pq.empty()){
        int dist = -pq.top().first;
        int node = pq.top().second;
        int sizee = adj[node].size();
        pq.pop();
        for(int i=0;i<sizee;i++)
        {
            int node_next = adj[node][i].first;
            int weight_next = adj[node][i].second;
            if(dis[node]+weight_next < dis[node_next])
            {
                dis[node_next] = dis[node]+weight_next;
                pq.emplace(-dis[node_next],node_next);
            }
        }
    }
}

int main(){
    read_input();
    init_dijkstra();
    dijkstra(dis[1],1);
    cout << dis[n];
    return 0;
}