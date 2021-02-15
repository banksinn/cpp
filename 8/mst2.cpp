#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100100;

priority_queue<pair<int,pair<int,int>>> pq;
int node[MAX_N];
int n,m;

void read_input(){
    int x,y,w;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> x >> y >> w;
        pq.push({-w,{x,y}});
    }
}

void init(){
    for (int i=1; i<MAX_N; i++){
        node[i] = i;
    }
}

int find_parent(int a){
    if (node[a]==a){
        return a;
    }
    return node[a] = find_parent(node[a]);
}

void union_find(int x,int y){
    int head_x,head_y;
    head_x = find_parent(x);
    head_y = find_parent(y);
    node[head_x] = node[head_y];
}

int find(int x,int y){
    int head_x,head_y;
    head_x = find_parent(x);
    head_y = find_parent(y);
    if (head_x==head_y){
        return 1;
    }
    else{
        return 0;
    }
}

void kruskal(){
    int val_x,val_y,val_w,head_x,head_y,ans=0;
    init();
    while (!pq.empty()){
        val_w = pq.top().first;
        val_x = pq.top().second.first;
        val_y = pq.top().second.second;
        pq.pop();
        if (!find(val_x,val_y)){
            union_find(val_x,val_y);
            ans += -val_w;
        }
    }
    cout << ans;
}

int main(){
    read_input();
    kruskal();
    return 0;
}
