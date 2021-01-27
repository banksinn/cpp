#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x,y;
    list<pair<int,int>> ball;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> x;
        ball.emplace_back(i+1,x);
    }
    for (int i=n; i<n+m; i++){
        cin >> x >> y;
        for (auto j=ball.begin(); j!=ball.end(); j++){
            if (j->first==y){
                j++;
                ball.emplace(j,i+1,x);
                break;
            }
        }

    }
    for (auto i=ball.begin(); i!=ball.end(); i++){
        cout << i->first << "\n";
    }
    return 0;
}
