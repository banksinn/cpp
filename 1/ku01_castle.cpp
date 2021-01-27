#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,floor=1;
    cin >> n;
    while (floor*floor<n){
        floor++;
    }
    //cout << "floor = " << floor << "\n";
    if ((floor%2==0 && n%2==0) || (floor%2!=0 && n%2!=0)){
        cout << 2*(floor-1);
    }
    else{
        cout << 2*(floor-1)-1;
    }
    return 0;
}
