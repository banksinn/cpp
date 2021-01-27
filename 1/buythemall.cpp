#include <bits/stdc++.h>
using namespace std;

int goods[3],price[3];

int main(){
    int p1,p2,p3,n,x,min_price;
    cin >> p1 >> p2 >> p3;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x;
        if (x==1){
            goods[0]++;
        }
        else if (x==2){
            goods[1]++;
        }
        else if (x==3){
            goods[2]++;
        }
    }
    price[0] = p1*goods[0];
    price[1] = p2*goods[1];
    price[2] = p3*goods[2];
    min_price = min(price[0],price[1]);
    min_price = min(min_price,price[2]);
    cout << min_price;
    return 0;
}
