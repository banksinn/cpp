#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50;
int n,m;
char table[MAX_N][MAX_N],new_table[MAX_N][MAX_N];

void read_table(){
    char c;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> c;
            table[i][j] = c;
        }
    }
    for (int i=0; i<n-1; i++){
        for (int j=0; j<m-1; j++){
            if (table[i][j]=='.' && table[i][j+1]=='.' && table[i+1][j]=='.' && table[i+1][j+1]=='.'){
                new_table[i][j] = '.';
            }
            else{
                new_table[i][j] = '#';
            }
        }
    }
}

void show_table(){
    cout << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << new_table[i][j] << " ";
        }
        cout << endl;
    }
}

bool visited[MAX_N][MAX_N];

void init_DFS(){
    for (int i=0; i<MAX_N; i++){
        for (int j=0; j<MAX_N; j++){
            visited[i][j] = false;
        }
    }
}

bool box=false;

void dfs(int i, int j){
    visited[i][j] = true;
    //new_table[i][j] = 'x';
    /*if (i==n-2 && new_table[i][j]=='.'){
        box = true;
    }*/
    if (i+1<n-1 && !visited[i+1][j] && new_table[i+1][j]=='.'){
        dfs(i+1,j);
    }
    if (j+1<m-1 && !visited[i][j+1] && new_table[i][j+1]=='.'){
        dfs(i,j+1);
    }
    if (i-1>-1 && !visited[i-1][j] && new_table[i-1][j]=='.'){
        dfs(i-1,j);
    }
    if (j-1>-1 && !visited[i][j-1] && new_table[i][j-1]=='.'){
        dfs(i,j-1);
    }
}


int main(){
    read_table();
    init_DFS();
    for (int i=0; i<m-1; i++){
        if (!visited[0][i] && new_table[0][i]=='.'){
            dfs(0,i);
        }
        else{
            visited[0][i] = true;
        }
    }
    for (int i=0; i<m-1; i++){
        if (visited[n-2][i]==true){
            box = true;
            break;
        }
    }
    if (box==true){
        cout << "yes";
    }
    else {
        cout << "no";
    }
    //show_table();
    return 0;
}

