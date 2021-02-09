#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100010;

list<pair<int,int>> maxlate;
list<int> keep_diff,deadline;
list<int>::iterator it;
int n;

void read_input(){
    int x,y;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x >> y;
        maxlate.emplace_back(x,y);
        deadline.push_back(x);
    }
    deadline.sort();
}

void maximum_late(){
    int time=0,diff;
    it = deadline.begin();
    maxlate.sort();
    for (auto i=maxlate.begin(); i!=maxlate.end(); i++){
        time += i->second;
        diff = time-*it;
        it++;
        keep_diff.push_back((diff-10)*1000);
    }
    keep_diff.sort();
    if (keep_diff.back()<=0){
        cout << 0;
    }
    else{
        cout << keep_diff.back();
    }
}

int main(){
    read_input();
    maximum_late();
    return 0;
}