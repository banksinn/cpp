#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    map<int,int> like;
    map<int,int>::iterator it;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x;
        like[x]++;
        if (like.size()==1){
            it = like.begin();
            cout << it->first << "\n";
        }
        else if (like[x]>=like[it->first]){
            it = like.find(x);
            cout << it->first << "\n";
        }
        else{
            cout << it->first << "\n";
        }
        //cout << like[x] << " " << like[it->first]<< endl;
    }
    return 0;
}
