#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1010;

int ladder[MAX_N];

int main(){
    int n,m,x;
    int ans=-1;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> x;
        ladder[i] = x;
    }
    for (int i=0; i<m; i++){
        cin >> x;
        ans += x;
        if (ladder[ans]!=0){
            //cout << "ladder: " << ladder[ans] << "\n";
            ans += ladder[ans];
        }
        //cout << ans << "\n";
        if (ans>=n){
            ans = n-1;
        }
        if (ans<0){
            ans = -1;
        }
    }
    if (ans<0){
        cout << 0;
    }
    else{
        cout << ans+1;
    }
    return 0;
}
