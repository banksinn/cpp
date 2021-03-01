#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100100;

int n;
long long int ans = 0;;
int arr[MAX_N], sort_arr[MAX_N];

void MergeSort_inversion(int L, int R){
    if(L == R){
        return;
    }
    int mid = (L+R)/2;
    MergeSort_inversion(L, mid);
    MergeSort_inversion(mid+1, R);
    int i = L, j = mid+1, idx = L;
    while(i <= mid && j <= R){
        if(arr[i] <= arr[j]){
            sort_arr[idx++] = arr[i++];
        }
        else if(arr[i] > arr[j]){
            sort_arr[idx++] = arr[j++];
            ans+=mid-i+1; //เพิ่มบรรทัดนี้ จาก merge sort นับ inversion
        }
    }
    while(i <= mid){
        sort_arr[idx++] = arr[i++];
    }
    while(j <= R){
        sort_arr[idx++] = arr[j++];
    }
    for(int i = L; i <= R; ++i){
        arr[i] = sort_arr[i];
    }
    return;
}

int main(){
    int x;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x;
        arr[i] = x;
    }
    MergeSort_inversion(0,n-1);
    cout << ans;
    return 0;
}