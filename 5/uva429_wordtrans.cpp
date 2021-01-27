#include <bits/stdc++.h>
using namespace std;

char word[200][10];
vector<int> adj[200];
map<string,int> m_word;
int deg[200];
int count_word=0;

void read_input(){
    string s;
    while (s!="*"){
        getline(cin >> ws, s);
        if (s=="*"){
            break;
        }
        m_word[s] = count_word;
        for (int j=0; j<s.size(); j++){
            word[count_word][j] = s[j];
        }
        if (count_word>0){
            for (int j=0; j<count_word; j++){
                int diff=0;
                if (strlen(word[j])!=s.size()){
                    continue;
                }
                for (int k=0; k<s.size(); k++){
                    if (word[j][k]!=s[k]){
                        diff++;
                    }
                }
                if (diff==1){
                    adj[j].push_back(count_word);
                    adj[count_word].push_back(j);
                    deg[j]++;
                    deg[count_word]++;
                }
            }
        }
        count_word++;
    }
}

void show_word(){
    for (int i=0; i<count_word; i++){
        for (int j=0; j<strlen(word[i]); j++){
            cout << word[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

bool discovered[200];
int layer[200];

void init_BFS(){
    for (int i=0; i<count_word; i++){
        discovered[i] = false;
    }
}

void bfs(int s, int t, string ss, string tt){
    discovered[s] = true;
    if (ss==tt){
        cout << ss << " " << tt << " " << 0 << "\n";
    }
    else{
        //cout << s << " ";
        layer[s] = 0;
        queue<int> Q;
        Q.push(s);
        while (!Q.empty()){
            int U = Q.front();
            Q.pop();
            for (int d=0; d<deg[U]; d++){
                int v = adj[U][d];
                if (!discovered[v]){
                    Q.push(v);
                    discovered[v] = true;
                    //cout << v << " ";
                    layer[v] = layer[U] + 1;
                    if (t==v){
                        cout << ss << " " << tt << " " << layer[v] << "\n";
                        break;
                    }
                }
            }
        }
    }
}

void output(){
    string start;
    while (getline(cin, start) && start != ""){
        int keep_start,keep_stop;
        init_BFS();
        stringstream ss(start);
        string s, t;
        ss >> s >> t;
        keep_start = m_word[s];
        keep_stop = m_word[t];
        bfs(keep_start,keep_stop,s,t);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << "\n";
    for (int i=0; i<n; i++){
        int keep;
        read_input();
        //show_word();
        output();
        cout << "\n";
    }
    return 0;
}
