#include<bits/stdc++.h>
using namespace std;
vector<int>v[100005];
int chk[100005];
int c[100005];
int ans = 0;
void dfs(int a,int color)
{
    if(chk[a])
    {
        if(c[a] != color)
            ans=1;
        return;
    }
    chk[a] = 1;
    c[a] = color;
    for(auto it=v[a].begin();it!=v[a].end();it++)
    {
        if(color == 1)
            dfs(*it,2);
        else
            dfs(*it,1);
    }
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        ans = 0;
        dfs(1,1);
        if(ans)
            printf("no\n");
        else
            printf("yes\n");
        for(int a=1;a<=n;a++)
        {
            c[a] = 0;
            chk[a] = 0;
            v[a].clear();
        }

    }
}
