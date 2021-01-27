#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,x,a,b;
    map<int,int> warehouse;
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> x;
        if (x==1){
            cin >> a >> b;
            if (warehouse[a]==0){
                warehouse[a] = b;
            }
            else{
                warehouse[a] += b;
            }
        }
        else if (x==2){
            cin >> a;
            cout << warehouse[a] << "\n";
        }
        else if (x==3){
            cin >> a >> b;
            if (warehouse[a]<b){
                cout << warehouse[a] << "\n";
                warehouse[a] = 0;
            }
            else{
                cout << b << "\n";
                warehouse[a] -= b;
            }
        }
    }
    return 0;
}
