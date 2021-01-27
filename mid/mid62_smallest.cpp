#include <bits/stdc++.h>
using namespace std;

int n,q;
map<int,int> height;
map<int,int> heightt;
map<int,int>::iterator itmap;
set<int> set_height;
set<int>::iterator it;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int h,t,x;
    cin >> n >> q;
    for (int i=0; i<n; i++){
        cin >> h;
        set_height.insert(h);
        it = set_height.begin();
        height[i] = *it;
        heightt[*it] = i;
    }
    for (int i=0; i<q; i++){
        cin >> t;
        if (t==1){
            cin >> x;
            x--;
            cout << height[x] << "\n";
        }
        else if (t==2){
            cin >> x;
            itmap = heightt.lower_bound(x);
            if (x>height[0]){
                cout << 0 << "\n";
            }
            else{
                cout << itmap->second+1 << "\n";
            }
        }
    }
    return 0;
}
