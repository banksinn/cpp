#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x,sum;
    map<int,int> cost;
    map<int,int>::iterator it;
    cin >> n >> k;
    for (int i=0; i<n; i++){ //quicksum arr[i] += arr[i-1]
        cin >> x;
        if (i==0){
            cost[0] = 0;
            it = cost.begin();
        }
        x += it->first;
        cost[x] = i+1;
        it++;
    }
    /*for (auto i=cost.begin(); i!=cost.end(); i++){
        cout << i->first << "->" << i->second << endl;
    }*/
    for (int i=0; i<k; i++){
        int ans=0;
        cin >> x;
        it = cost.upper_bound(x);
        it--;
        cout << it->second << "\n";
    }
    return 0;
}
