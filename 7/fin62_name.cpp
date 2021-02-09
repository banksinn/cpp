#include <bits/stdc++.h>
using namespace std;

string s,t;

void read_input(){
    getline(cin>>ws, s);
    getline(cin>>ws, t);
}

void solve(){
    int index=0,count=0;
    for (int i=0; i<t.size(); i++){
        if (t[i]==s[index]){
            if (index==s.size()-1){
                index = 0;
                count++;
            }
            index++;
        }
    }
    cout << count;
}

int main(){
    read_input();
    solve();
    return 0;
}