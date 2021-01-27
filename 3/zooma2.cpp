#include <bits/stdc++.h>
using namespace std;

bool deleted[300000];
list<pair<int,int>> ball;
vector<list<pair<int,int>>::iterator> it;

int main(){
    int n,m,x,y;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> x;
        ball.emplace_back(i+1,x);
        auto ball_index = ball.end();
        ball_index--;
        it.push_back(ball_index);

    }
    for (int i=n; i<n+m; i++){
        vector<list<pair<int,int>>::iterator> keep;
        cin >> x >> y;
        if (deleted[y-1]==true){
            auto it1 = it[y-1];
            it.push_back(it1);
            deleted[i]=true;
            continue;
        }
        auto it1 = it[y-1];
        it1++;
        ball.emplace(it1,i+1,x);
        it1--;
        it.push_back(it1);
        //cout << "it1: "<< it1->first << "->" << it1->second << "\n";
        keep.push_back(it1);
        int consecutive=1;
        auto run = ++it1;
        //cout << "run: "<< run->first << "->" << run->second << "\n";
        it1--;
        //cout << "it1(again): "<< it1->first << "->" << it1->second << "\n";
        for (auto j=run; j!=ball.end(); j++){
            if (j->second==it1->second){
                consecutive++;
                keep.push_back(j);
                //cout << "j: "<< j->first << "->" << j->second << "," << "it1: " << it1->first << "->"<< it1->second << "\n";
            }
            else{
                break;
            }
        }
        //cout << "consecutive: " << consecutive << "\n";
        if (consecutive>=3){
            for (auto k=keep.begin(); k!=keep.end(); k++){
                auto ke = *k;
                deleted[(ke->first)-1] = true;
                ball.erase(*k);
            }
        }
        /*cout << "after delete:\n";
        for (auto a=ball.begin(); a!=ball.end(); a++){
            cout << a->first << "->" << a->second << "\n";
        }*/
        keep.clear();
    }
    for (auto d=ball.begin(); d!=ball.end(); d++){
        cout << d->first << "\n";
    }
    return 0;
}
