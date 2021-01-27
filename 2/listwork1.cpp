#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,x;
    char c;
    cin >> m;
    list<int> l;
    for (int i=0; i<m; i++){
        cin >> c >> x;
        if (c=='I'){
            l.push_front(x);
        }
        else if (c=='D'){
            list<int>::iterator li = l.begin();
            if (x>l.size()){
                continue;
            }
            advance(li, x-1); // Incrementing li by x positions
            l.erase(li);
        }
    }
    for (auto i = l.begin(); i != l.end(); i++){
        cout << *i << endl;
    }
    return 0;
}
