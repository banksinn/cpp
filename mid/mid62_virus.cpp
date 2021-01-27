#include <bits/stdc++.h>
using namespace std;

int n,m;
list<int> virus;
list<int>::iterator it;

void show_virus(){
    for (auto i=virus.begin(); i!=virus.end(); i++){
        cout << *i << " " << "\n";
    }
}

int main(){
    int x,y,t;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> x;
        virus.push_back(x);
    }
    it = virus.begin();
    for (int i=0; i<m; i++){
        cin >> t;
        if (t==1){
            it = virus.begin();
        }
        else if (t==2){
            it++;
            if (it==virus.end()){
                it = virus.begin();
            }
        }
        else if (t==3){
            cin >> y;
            virus.insert(it,y);
        }
        else if (t==4){
            cin >> y;
            it++;
            virus.insert(it,y);
            advance(it,-2);
        }
    }
    show_virus();
    return 0;
}
