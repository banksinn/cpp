#include <bits/stdc++.h>
using namespace std;

int main(){
    int l,n,floor_out=1;
    cin >> l >> n;
    while (n>=0){
        if (n==0){
            floor_out=0;
            break;
        }
        n -= floor_out*floor_out;
        if ((floor_out+1)*(floor_out+1)>n){
            break;
        }
        floor_out++;
    }
    cout << l-floor_out;
    return 0;
}
