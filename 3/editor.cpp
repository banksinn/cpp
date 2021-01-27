#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    char c;
    list<string> editor;
    list<string>::iterator it = editor.end();
    for (int i=0; i<n; i++){
        cin >> c;
        if (c=='l'){
            if (it!=editor.begin()){
                it--;
            }
        }
        else if (c=='r'){
            if (it!=editor.end()){
                it++;
            }
        }
        else if (c=='i'){
            getline(cin >> ws,s);
            editor.insert(it,s);
        }
        else if (c=='b'){
            if (it!=editor.begin()){
                it--;
                it = editor.erase(it);
            }
        }
        else if (c=='d'){
            if (it!=editor.end()){
                list<string>::iterator keep=it;
                keep++;
                it = editor.erase(it);
                it = keep;
            }
        }
        /*for (auto i=editor.begin(); i!=editor.end(); i++){
            cout << *i << " ";
        }
        cout << "\n";
        cout << "pointer: ";
        if (it==editor.end()){
            cout << "end\n";
        }
        else{
            cout << *it << endl;
        }*/
    }
    for (auto i=editor.begin(); i!=editor.end(); i++){
        cout << *i << " ";
    }
    return 0;
}
