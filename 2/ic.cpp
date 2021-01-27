#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,x;
    string c;
    list<int> ic;
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> c;
        if (c=="li"){
            cin >> x;
            ic.push_front(x);
        }
        else if (c=="ri"){
            cin >> x;
            ic.push_back(x);
        }
        else if (c=="lr"){
            ic.push_back(ic.front());
            ic.pop_front();
        }
        else if (c=="rr"){
            ic.push_front(ic.back());
            ic.pop_back();
        }
    }
    for (auto i = ic.begin(); i != ic.end(); i++){
        cout << *i << endl;
    }
    return 0;
}
