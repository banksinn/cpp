#include <bits/stdc++.h>
using namespace std;

int main(){
    int x=0,y=0;
    string inp;
    getline(cin >> ws,inp);
    for (int i=0;i<inp.size();i++){
        if (inp[i]=='N'){
            y++;
        }
        else if (inp[i]=='E'){
            x++;
        }
        else if (inp[i]=='S'){
            y--;
        }
        else if (inp[i]=='W'){
            x--;
        }
        else if (inp[i]=='Z'){
            x=0;
            y=0;
        }
    }
    cout << x << " " << y;
    return 0;
}
