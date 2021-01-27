#include <bits/stdc++.h>
using namespace std;

list<int> nec[300000];
int parent[300000];

int findroot (int x){
    while (x!=parent[x-1]){
        x=parent[x-1];
    }
    return x-1;
}

int main(){
    int n,x,y;
    cin >> n;
    for (int i=0; i<n; i++){
        nec[i].push_back(i+1);
        parent[i] = i+1;
    }
    for (int i=0; i<n-1; i++){
        cin >> x >> y;
        /*for (int j=0; j<n; j++){
            for (auto k = nec[j].begin(); k != nec[j].end(); k++){
                if (*k==y){
                    nec[j].splice(k,nec[x-1],nec[x-1].begin(),nec[x-1].end());
                }
            }
        }*/
        int parx = findroot(x);
        int pary = findroot(y);
        for (auto j=nec[pary].begin(); j!=nec[pary].end(); j++){
            if (y==*j){
                j++;
                nec[pary].splice(j,nec[parx],nec[parx].begin(),nec[parx].end());
                parent[parx] = pary+1;
                break;
            }
        }
    }
    for (int i=0; i<n; i++){
        if (nec[i].size()>0){
            for (auto j = nec[i].begin(); j != nec[i].end(); j++){
                cout << *j << " ";
            }
        }
    }
    return 0;
}
