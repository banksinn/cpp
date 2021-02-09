#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100010;

list<pair<int,int>> schedule,st;
int n ,l=0;

void read_input(){
    int x,y;
    cin >> n;
    for (int a=0; a<n; a++){
        cin >> x >> y;
        st.emplace_back(y,x);
    }
}

void interval_schedule(){
    st.sort();
    // for (auto i=st.begin(); i!=st.end(); i++){
    //     cout << i->first << " " << i->second << "\n";
    // }
    // cout << "\n";
    for (auto b=st.begin(); b!=st.end(); b++){
        if (b->second>=l){
            schedule.emplace_back(b->second,b->first);
            l = b->first;
        }
    }
    // for (auto c=schedule.begin(); c!=schedule.end(); c++){
    //     cout << c->first << " " << c->second << "\n";
    // }
}

int main(){
    read_input();
    interval_schedule();
    cout << schedule.size();
    return 0;
}