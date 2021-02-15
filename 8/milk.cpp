#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100100;
int milk[MAX_N];
int a,b;

void init(){
    for (int i=1; i<MAX_N; i++){
        milk[i] = i;
    }
}

int find_parent(int a){
    if (milk[a]==a){
        return a;
    }
    return milk[a] = find_parent(milk[a]);
}

void union_find(int x,int y){
    int head_x,head_y;
    head_x = find_parent(x);
    head_y = find_parent(y);
    milk[head_x] = milk[head_y];
}

void find(int x,int y){
    int head_x,head_y;
    head_x = find_parent(x);
    head_y = find_parent(y);
    if (head_x==head_y){
        cout << "yes\n";
    }
    else{
        cout << "no\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char input;
    int x,y;
    cin >> a >> b;
    init();
    for (int i=0; i<b; i++){
        cin >> input >> x >> y;
        if (input=='c'){
            union_find(x,y);
        }
        else if (input=='q'){
            find(x,y);
        }
    }
    return 0;
}