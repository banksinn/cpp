#include <bits/stdc++.h>
using namespace std;

int under[600];

int main(){
    int l,n,x,y;
    cin >> l >> n;
    for (int i=0;i<n;i++){
        cin >> x >> y;
        for (int j=2*x+1;j<2*y;j++){
            under[j]++;
        }
    }
    sort(under,under+600,greater<int>());
    cout << under[0];
    return 0;
}
