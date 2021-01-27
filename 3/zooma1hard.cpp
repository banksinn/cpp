#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x,y;
    list<pair<int,int>> ball;
    vector<list<pair<int,int>>::iterator> it;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> x;
        ball.emplace_back(i+1,x);
        auto ball_index = ball.end();
        ball_index--;
        it.push_back(ball_index);

    }
    for (int i=n; i<n+m; i++){
        cin >> x >> y;
        auto it1 = it[y-1];
        it1++;
        ball.emplace(it1,i+1,x);
        it1--;
        it.push_back(it1);
    }
    for (auto i=ball.begin(); i!=ball.end(); i++){
        cout << i->first << "\n";
    }
    return 0;
}
