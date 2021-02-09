#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v[100005];
priority_queue<pair<int,int>>pq;
int dis[100005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int uu,vv,wei;
        scanf("%d%d%d",&uu,&vv,&wei);
        v[uu].push_back({vv,wei});
        v[vv].push_back({uu,wei});
    }
    for(int i=1;i<=n;i++)
        dis[i] = 1e9;
    dis[1] = 0;
    pq.push({-dis[1],1});
    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int node = pq.top().second;
        int sizee = v[node].size();
        pq.pop();
        for(int i=0;i<sizee;i++)
        {
            int des = v[node][i].first;
            int wei = v[node][i].second;
            if(dis[node]+wei < dis[des])
            {
                dis[des] = dis[node]+wei;
                pq.push({-dis[des],des});
            }
        }
    }
    printf("%d",dis[n]);
}