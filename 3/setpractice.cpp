#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x;
    set<int> queries;
    list<int> ans;
    set<int>::iterator it1,it2,keep;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> x;
        queries.insert(x);
    }
    for (int i=0; i<m; i++){
        cin >> x;
        it2 = queries.lower_bound(x);
        if (it2==queries.end()){
            it2--;
            it1 = it2;
        }
        else{
            keep = it2;
            keep--;
            it1 = keep;
        }
        if (abs(*it1-x)<=abs(*it2-x)){
            ans.push_back(*it1);
        }
        else{
            ans.push_back(*it2);
        }
    }
    for (auto i=ans.begin(); i!=ans.end(); i++){
        cout << *i << endl;
    }
    return 0;
}
