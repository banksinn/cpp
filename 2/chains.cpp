#include <bits/stdc++.h>
using namespace std;

list<int> m[100000],chain;

int main(){
    int n,l,x,y,keep=1,index=0;
    char c;
    cin >> n >> l;
    for (int i=0; i<n ;i++){
        cin >> x;
        for (int j=0; j<x; j++){
            m[i].push_back(keep);
            keep++;
        }
    }
    for (int i=0; i<n; i++){
        for (auto j=m[i].begin(); j!=m[i].end(); j++){
            cout << i << '=' << *j << endl;
        }
    }
    chain.splice(chain.begin(),m[index]);
    /*for (auto i=chain.begin(); i!=chain.end(); i++){
        cout << *i << endl;
    }*/
    list<int>::iterator it;
    it = chain.begin();
    for (int i=0; i<l; i++){
        cin >> c;
        if (c=='B'){
            if (it==chain.begin()){
                it = chain.begin();
            }
            else{
                it--;
            }
        }
        else if (c=='F'){
            if (it==chain.end()){
                it = chain.end();
            }
            else{
                it++;
            }
        }
        else if (c=='C'){
            cin >> y;
            if (it==chain.end()){
                cout << "pass" << endl;
            }
            else{
                advance(it,1);
                list<int>::iterator keep_it=it;
                m[index].splice(m[index].begin(),chain,keep_it,chain.end());
                /*for (auto j=chain.begin(); j!=chain.end(); j++){
                    cout << *j << endl;
                }*/
                it = chain.end();
                //cout << "it=" << *it << endl;
                int check = 0;
                for (int j=0; j<100000; j++){
                    for (auto k=m[j].begin(); k!=m[j].end(); k++){
                        if (*k==y){
                            check = 1;
                            index = j;
                            break;
                        }
                    }
                    if (check==1){
                        break;
                    }
                }

                //cout << "index=" << *add << " " << *m[index].end() << endl;
                /*if (add==m[index].begin()){
                    cout << "pass";
                }*/
                //cout << "it=" << *it << endl;
                int keep_count = 0;
                for (auto j=m[index].begin(); j!=m[index].end(); j++){
                    if (y==*j){
                        if (keep_count==0){
                            chain.splice(it,m[index],m[index].begin(),m[index].end());
                        }
                        else{
                            m[index].reverse();
                            chain.splice(it,m[index],m[index].begin(),m[index].end());
                        }

                        break;
                    }
                    keep_count++;
                }
                it = chain.end();
                cout << "it=" << *it << endl;
            }
        }
    }
    for (auto j=chain.begin(); j!=chain.end(); j++){
            cout << *j << endl;
    }
    //cout << *it;
    return 0;
}
