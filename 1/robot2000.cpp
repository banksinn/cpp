#include <bits/stdc++.h>
using namespace std;

int main(){
    int direction=0;
    string inp;
    getline(cin >> ws,inp);
    for (int i=0;i<inp.size();i++){
        if (inp[i]=='N'){
            while (direction!=0){
                direction++;
                cout << 'R';
                direction %= 4;
            }
            cout << 'F';
        }
        else if (inp[i]=='E'){
            while (direction!=1){
                direction++;
                cout << 'R';
                direction %= 4;
            }
            cout << 'F';
        }
        else if (inp[i]=='S'){
            while (direction!=2){
                direction++;
                cout << 'R';
                direction %= 4;
            }
            cout << 'F';
        }
        else if (inp[i]=='W'){
            while (direction!=3){
                direction++;
                cout << 'R';
                direction %= 4;
            }
            cout << 'F';
        }
        else if (inp[i]=='Z'){
            direction=0;
            cout << 'Z';
        }
    }
    return 0;
}
