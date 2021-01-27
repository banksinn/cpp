#include <bits/stdc++.h>
using namespace std;

int x[1000],y[1000],area[1001][1001];

int main(){
    int w,h,m,n,first=0,second=0,keep;
    cin >> w >> h >> m >> n;
    for (int i=0;i<m;i++){
        cin >> x[i];
    }
    for (int i=0;i<n;i++){
        cin >> y[i];
    }
    for (int i=0;i<n+1;i++){
        for (int j=0;j<m+1;j++){
            if (i==0 && j==0){
                area[i][j] = x[j]*y[i];
            }
            else if (i==0 && j==m){
                area[i][j] = (w-x[j-1])*y[i];
            }
            else if (i==n && j==0){
                area[i][j] = x[j]*(h-y[i-1]);
            }
            else if (i==n && j==m){
                area[i][j] = (w-x[j-1])*(h-y[i-1]);
            }
            else if (i==0){
                area[i][j] = (x[j]-x[j-1])*y[i];
            }
            else if (i==n){
                area[i][j] = (x[j]-x[j-1])*(h-y[i-1]);
            }
            else if (j==0){
                area[i][j] = x[j]*(y[i]-y[i-1]);
            }
            else if (j==m){
                area[i][j] = (w-x[j-1])*(y[i]-y[i-1]);
            }
            else{
                area[i][j] = (x[j]-x[j-1])*(y[i]-y[i-1]);
            }
        }
    }
    /*for (int i=0;i<n+1;i++){
        for (int j=0;j<m+1;j++){
            cout << area[i][j] << " ";
        }
        cout << "\n";
    }*/
    for (int i=0;i<n+1;i++){
        for (int j=0;j<m+1;j++){
            if (i==0 && j==0){
                first = max(first,area[i][j]);
            }
            else if (area[i][j] >= first){
                keep = first;
                first = max(first,area[i][j]);
                second = keep;
            }
            else{
                second = max(second,area[i][j]);
            }
        }
    }
    cout << first << " ";
    cout << second;
    return 0;
}
