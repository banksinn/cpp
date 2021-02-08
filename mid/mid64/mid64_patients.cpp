#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1010;

int n;
int patient[MAX_N];

void solve(){
    int x,y,z,ans=0;
    cin >> n;
    for (int i=1; i<n+1; i++){
        cin >> x;
        for (int j=0; j<x; j++){
           cin >> y >> z;
           patient[i] += y;
           patient[i+z] -= y;
        }
        ans += patient[i];
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
