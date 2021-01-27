#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,h[1000],ans=0;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> h[i];
    }
    for (int i=0;i<n;i++){
        if (i==0){
            if (h[i]>h[i+1]){
                ans++;
            }
        }
        else if (i==n-1){
            if (h[i]>h[i-1]){
                ans++;
            }
        }
        else{
            if (h[i]>h[i-1] && h[i]>h[i+1]){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
