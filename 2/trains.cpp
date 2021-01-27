#include <bits/stdc++.h>
using namespace std;

list<int> train[100000];

int main(){
    int m,x,y;
    char c;
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> c >> x >> y;
        if (c=='N'){
            train[y-1].push_back(x);
        }
        else if (c=='M'){
            train[y-1].splice(train[y-1].end(),train[x-1]);
        }
    }
    for (int i=0; i<100000; i++){
        for (auto j = train[i].begin(); j != train[i].end(); j++){
            cout << *j << endl;
        }
    }
    return 0;
}
