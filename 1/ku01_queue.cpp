#include <bits/stdc++.h>
using namespace std;

int row[100000],customer[100];

int main(){
    int n,l,h_max;
    cin >> n >> l;
    for (int i=0;i<n;i++){
        cin >> row[i];
    }
    for (int i=0;i<l;i++){
        cin >> customer[i];
    }
    h_max = row[0];
    for (int i=0;i<l;i++){
        for (int j=0;j<customer[i]-1;j++){
            h_max = max(h_max,row[j]);
        }
        if (customer[i]==1){
            cout << 0 << "\n";
        }
        else if (row[customer[i]-1]>h_max){
            cout << 0 << "\n";
        }
        else{
            cout << h_max-row[customer[i]-1]+1 << "\n";
        }
    }
    return 0;
}
