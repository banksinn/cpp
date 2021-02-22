#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2000200;

int n;
int arr[MAX_N],sort_arr[MAX_N];

void init_array(){
    for (int i=0; i<MAX_N; i++){
        arr[i] = 0;
    }
}

void MergeSort(int L, int R){
    if(L == R)
        return;
    int mid = (L+R)/2;
    MergeSort(L, mid);
    MergeSort(mid+1, R);
    int i = L, j = mid+1, idx = L;
    while(i <= mid && j <= R){
        if(arr[i] <= arr[j])
            sort_arr[idx++] = arr[i++];
        else if(arr[i] > arr[j])
            sort_arr[idx++] = arr[j++];
    }
    while(i <= mid)
        sort_arr[idx++] = arr[i++];
    while(j <= R)
        sort_arr[idx++] = arr[j++];
    for(int i = L; i <= R; ++i)
        arr[i] = sort_arr[i];
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n && n!=0){
        init_array();
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }
        MergeSort(0,n-1);
        for (int i=0; i<n; i++){
            if (i==n-1){
                cout << arr[i];
            }
            else{
                cout << arr[i] << " ";

            }
        }
        cout << "\n";
    }
    return 0;
}