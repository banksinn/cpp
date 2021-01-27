#include <bits/stdc++.h>
using namespace std;

int main(){
    string inp;
    int n=0,e=0,s=0,w=0,k,min_ns,min_ew,keep;
    getline(cin >> ws,inp);
    cin >> k;
    for (int i=0;i<inp.size();i++){
        if (inp[i]=='N'){
            n++;
        }
        else if (inp[i]=='E'){
            e++;
        }
        else if (inp[i]=='S'){
            s++;
        }
        else if (inp[i]=='W'){
            w++;
        }
    }
    //cout << "n e s w k\n";
    //cout << n << " " << e << " " << s << " " << w << " " << k << "\n";
    if (n-s>=0 && e-w>=0){
        int keep = k;
        for (int i=keep;i>0;i--){
            if (s>0){
                s--;
                k--;
            }
            else if (w>0){
                w--;
                k--;
            }
            else if (n>0){
                n--;
                k--;
            }
            else if (e>0){
                e--;
                k--;
            }
        }
    }
    else if (n-s>=0 && e-w<=0){
        int keep = k;
        for (int i=keep;i>0;i--){
            if (s>0){
                s--;
                k--;
            }
            else if (e>0){
                e--;
                k--;
            }
            else if (n>0){
                n--;
                k--;
            }
            else if (w>0){
                w--;
                k--;
            }
        }
    }
    else if (n-s<=0 && e-w<=0){
        int keep = k;
        for (int i=keep;i>0;i--){
            if (n>0){
                n--;
                k--;
            }
            else if (e>0){
                e--;
                k--;
            }
            else if (s>0){
                s--;
                k--;
            }
            else if (w>0){
                w--;
                k--;
            }
        }
    }
    else if (n-s<=0 && e-w>=0){
        int keep = k;
        for (int i=keep;i>0;i--){
            if (n>0){
                n--;
                k--;
            }
            else if (w>0){
                w--;
                k--;
            }
            else if (s>0){
                s--;
                k--;
            }
            else if (e>0){
                e--;
                k--;
            }
        }
    }
    //cout << n << " " << e << " " << s << " " << w << " " << k << "\n";
    cout << 2*(abs(n-s)+abs(e-w));
    return 0;
}
