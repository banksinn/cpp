#include <bits/stdc++.h>
using namespace std;

int main(){
    int l,n,row=1,sum=0;
    cin >> l >> n;
    while (sum<=n){
        sum += ((l*(l+1)/2)+l*l*(row-1));
        //cout << "row=" << row << "sum=" << sum << "\n";
        if (sum>=n){
            break;
        }
        row++;
    }
    cout << row;
    return 0;
}
