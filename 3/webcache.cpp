#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x,ans=0;
    queue<int> pos_cache;
    set<int> cache={1000001};
    set<int>::iterator it;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> x;
        if (cache.size()==n+1){
            it = cache.lower_bound(x);
            if (*it!=x){
                cache.erase(pos_cache.front());
                pos_cache.pop();
                cache.insert(x);
                pos_cache.push(x);
                ans++;
            }
        }
        else{
            it = cache.lower_bound(x);
            if (*it!=x){
                cache.insert(x);
                pos_cache.push(x);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
