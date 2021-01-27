#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x,sum=0;
    char operand;
    cin >> n;
    cin >> x;
    sum = x;
    for (int i=1;i<n;i++){
        cin >> operand;
        cin >> x;
        if (operand=='+'){
            sum += x;
        }
        else if (operand=='-'){
            sum -= x;
        }
    }
    cout << sum;
    return 0;
}
