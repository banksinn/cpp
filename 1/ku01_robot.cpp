#include <bits/stdc++.h>
using namespace std;

int main(){
    int h1,h2,b1,b2,x,y,same=0,diff=0,min_same,min_diff;
    cin >> h1 >> h2 >> b1 >> b2;
    cin >> x >> y;
    if (x>=y){
        min_same = min(h1,b1);
        min_same = min(min_same,x);
        same += min_same;
        h1 -= min_same;
        b1 -= min_same;
        min_same = min(h2,b2);
        min_same = min(min_same,x);
        same += min_same;
        h2 -= min_same;
        b2 -= min_same;
        min_diff = min(h1,b2);
        min_diff = min(min_diff,y);
        diff += min_diff;
        min_diff = min(h2,b1);
        min_diff = min(min_diff,y);
        diff += min_diff;
    }
    else{
        min_diff = min(h1,b2);
        min_diff = min(min_diff,y);
        diff += min_diff;
        h1 -= min_diff;
        b2 -= min_diff;
        min_diff = min(h2,b1);
        min_diff = min(min_diff,y);
        diff += min_diff;
        h2 -= min_diff;
        b1 -= min_diff;
        min_same = min(h1,b1);
        min_same = min(min_same,x);
        same += min_same;
        min_same = min(h2,b2);
        min_same = min(min_same,x);
        same += min_same;
    }
    cout << same+diff;
    return 0;
}
