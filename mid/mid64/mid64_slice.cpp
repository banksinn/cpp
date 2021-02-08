#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100010;

int slice[MAX_N];
vector<int> le[MAX_N];
vector<int>:iterator it;
int n;

void read_input(){
    int x;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x;
        slice[i] = x;
    }
    for (int i=0; i<MAX_N; i++){
        le[i].push_back(0);
        le[i].push_back(n+2);
        it = le[i].begin();
        it++;

    }
}

int main(){

    return 0;
}
