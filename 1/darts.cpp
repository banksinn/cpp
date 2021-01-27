#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x,y,sum=0;
    float r;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x >> y;
        r = sqrt(x*x+y*y);
        if (r>10){
            sum += 0;
        }
        else if (r>8){
            sum += 1;
        }
        else if (r>6){
            sum += 2;
        }
        else if (r>4){
            sum += 3;
        }
        else if (r>2){
            sum += 4;
        }
        else{
            sum += 5;
        }
    }
    cout << sum;
    return 0;
}
