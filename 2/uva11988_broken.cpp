#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while (getline(cin >> ws,s)){
        int check = 0;
        list<char> keyboard;
        list<char>::iterator it;
        for (char c:s){
            if (c=='['){
                check = 1;
                it = keyboard.begin();
                continue;
            }
            else if (c==']'){
                check = 0;
                continue;
            }
            if (check==1){
                keyboard.insert(it,c);
            }
            else if (check==0){
                keyboard.push_back(c);
            }
        }
        for (auto i=keyboard.begin(); i!=keyboard.end(); i++){
            cout << *i;
        }
        cout << "\n";
    }
    return 0;
}
