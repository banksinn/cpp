#include <bits/stdc++.h>
using namespace std;

int n,m;
char table[50][50];

void read_table(){
    char c;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> c;
            table[i][j] = c;
        }
    }
}

bool discovered[50][50];

void init(){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            discovered[i][j] = false;
        }
    }
}

int count1=0,count2=0;

void bfs(int i, int j){
    int keep = 0;
    discovered[i][j] = true;
    queue<pair<int,int>> travel;
    set<char> quality;
    travel.emplace(i,j);
    while (!travel.empty()){
        auto d=travel.front();
        i=d.first; j=d.second;
        travel.pop();
        if (table[i][j]=='#'){
            continue;
        }
        if (table[i][j]=='*' || table[i][j]=='$'){
            quality.insert(table[i][j]);
        }
        keep++;
        if (j+1<m && !discovered[i][j+1]){
            discovered[i][j+1] = true;
            travel.emplace(i,j+1);
        }

        if (j-1>-1 && !discovered[i][j-1]){
            discovered[i][j-1] = true;
            travel.emplace(i,j-1);
        }
        if (i+1<n && !discovered[i+1][j]){
            discovered[i+1][j] = true;
            travel.emplace(i+1,j);
        }
        if (i-1>-1 && !discovered[i-1][j]){
            discovered[i-1][j] = true;
            travel.emplace(i-1,j);
        }
    }
    if (quality.size()==1){
        count1 += keep;
    }
    else if (quality.size()==2){
        count2 += keep;
    }
}

int main(){
    read_table();
    init();
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!discovered[i][j]){
                bfs(i,j);
            }
        }
    }
    cout << count2 << " " << count1;
    return 0;
}
