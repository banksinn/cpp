#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while (1){
        cin >> n;
        if (n==0){
            break;
        }
        while (n){
            int x,count=1;
            stack<int> train;
            list<int> compare;
            for (int i=0; i<n; i++){
                int keep=0,mark=0;
                cin >> x;
                if (x==0){
                    n = 0;
                    break;
                }
                for (int j=count; j<=x; j++){
                    mark++;
                    keep = 1;
                    train.push(j);
                }
                if (x==train.top()){
                    train.pop();
                }
                if (keep==1){
                    count += mark;
                }
            }
            if (n==0){
                cout << "\n";
                break;
            }
            if (train.empty()){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }
    return 0;
}
