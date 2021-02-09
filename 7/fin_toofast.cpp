#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100100;

vector<pair<int,int>> adj[MAX_N],expressway[MAX_N];
vector<int> weight_expressway[MAX_N];
list<int> ans;
int dis[MAX_N];
int n,m,count_expressway=0;

void read_input(){
    int x,y,weight,s;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> x >> y >> weight >> s;
        if (s==0){
            adj[x].emplace_back(y,weight);
            adj[y].emplace_back(x,weight);
        }
        else{
            expressway[count_expressway].emplace_back(x,y);
            weight_expressway[count_expressway].push_back(weight);
            count_expressway++;
        }
    }
}

void init_dijkstra(){
    for (int i=1; i<MAX_N; i++){
        dis[i] = 100100;
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
    ans.push_back(dis[n]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int first,second,weightt;
    read_input();
    for (int a=0; a<count_expressway; a++){
        first = expressway[a][0].first;
        second = expressway[a][0].second;
        weightt = weight_expressway[a][0];
        init_dijkstra();
        adj[first].emplace_back(second,weightt);
        adj[second].emplace_back(first,weightt);
        dijkstra(dis[1],1);
        adj[first].pop_back();
        adj[second].pop_back();
    }
    ans.sort();
    if (ans.front()==100100){
        cout << -1;
    }
    else{
        cout << ans.front();
    }
    return 0;
}