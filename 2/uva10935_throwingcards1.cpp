#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while (cin >> n){
        int count = 1;
        queue<int> card;
        if (n==0){
            break;
        }
        for (int i=1; i<n+1; i++){
            card.push(i);
        }
        cout << "Discarded cards:";
        while (card.size()>1){
            if (count%2==0){
                card.push(card.front());
                card.pop();
                count++;
            }
            cout << " " << card.front();
            if (card.size()!=2){
                cout << ",";
            }
            card.pop();
            count++;
        }
        cout << "\n";
        cout << "Remaining card: " << card.front() << "\n";
    }
    return 0;
}
