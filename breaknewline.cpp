#include <bits/stdc++.h>
using namespace std;

int main(){
    string start;
    while (getline(cin, start) && start != ""){
        stringstream ss(start);
        string s, t;
        ss >> s >> t;
        cout << "output: "<< s << " " << t << "\n";
    }
    return 0;
}
