#include <bits/stdc++.h>
using namespace std;

int n,m;
set<int> cost_book[1010];
int money[100100];

void read_input(){
    int x[1010];
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> x[i];
    }
    cost_book[0].insert(0);
    for (int i=0; i<n; i++){
        int keep=0,index=1;
        for (int j=i; j<n; j++){
            keep += x[j];
            cost_book[index].insert(keep);
            index++;
        }
    }
    for (int i=0; i<m; i++){
        cin >> money[i];
    }
}

void solve(){
    map<int,int> keep_cost;
    map<int,int>::iterator it;
    for (int i=0; i<n+1; i++){
        auto cost=cost_book[i].begin();
        keep_cost[*cost] = i;
    }
    for (int i=0; i<m; i++){
        it = keep_cost.lower_bound(money[i]);
        if (it->first!=money[i]){
            it--;
        }
        cout << it->second << "\n";
    }
}

void show(){
    for (int i=0; i<n+1; i++){
        auto cost=cost_book[i].begin();
        cout << *cost << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    //show();
    return 0;
}
