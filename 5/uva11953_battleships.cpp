#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 110;
char table[MAX_N][MAX_N];

void read_table(int n){
    char c;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> c;
            table[i][j] = c;
        }
    }
}

void init_table(){
    for (int i=0; i<MAX_N; i++){
        for (int j=0; j<MAX_N; j++){
            table[i][j] = NULL;
        }
    }
}

bool visited[MAX_N][MAX_N];

void init_visited(){
    for (int i=0; i<MAX_N; i++){
        for (int j=0; j<MAX_N; j++){
            visited[i][j] = false;
        }
    }
}

int dfs(int i, int j, int n){
    visited[i][j] = true;
    if (table[i][j]=='.'){
        return 0;
    }
    else if (table[i][j]=='x') {
        if (j+1<n && !visited[i][j+1] && (table[i][j+1]=='x' || table[i][j+1]=='@')){
            table[i][j+1] = 'x';
            dfs(i,j+1,n);
        }
        if (j-1>-1 && !visited[i][j-1] && (table[i][j-1]=='x' || table[i][j-1]=='@')){
            table[i][j-1] = 'x';
            dfs(i,j-1,n);
        }
        if (i+1<n && !visited[i+1][j] && (table[i+1][j]=='x' || table[i+1][j]=='@')){
            table[i+1][j] = 'x';
            dfs(i+1,j,n);
        }
        if (i-1>-1 && !visited[i-1][j] && (table[i-1][j]=='x' || table[i-1][j]=='@')){
            table[i-1][j] = 'x';
            dfs(i-1,j,n);
        }
        return 1;
    }
    else if (table[i][j]=='@'){
        if (j+1<n && !visited[i][j+1] && table[i][j+1]=='@'){
            dfs(i,j+1,n);
        }
        if (j-1>-1 && !visited[i][j-1] && table[i][j-1]=='@'){
            dfs(i,j-1,n);
        }
        if (i+1<n && !visited[i+1][j] && table[i+1][j]=='@'){
            dfs(i+1,j,n);
        }
        if (i-1>-1 && !visited[i-1][j] && table[i-1][j]=='@'){
            dfs(i-1,j,n);
        }
        return 0;
    }
    else{
        return 0;
    }
}

int main(){
    int t,n;
    cin >> t;
    for (int i=0; i<t; i++){
        int ans=0;
        cin >> n;
        init_table();
        init_visited();
        read_table(n);
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                if (!visited[j][k]){
                    ans += dfs(j,k,n);
                }
            }
        }
        cout << "Case " << i+1 << ": " << ans << endl;
    }
    return 0;
}
