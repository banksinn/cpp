#include <bits/stdc++.h>
#include "probelib.h"
using namespace std;

int main()
{
    int n=0, m=probe_init();
    for(int i=0; i<22; i++) {
        if (probe_check(n,n+((m-n)/2))) {
            //printf("n = %d, check1=%d, m=%d\n",n,n+((m-n)/2),m);
            m = n+((m-n))/2;
            //printf("i = %d\n",i);
        }
        else{
            //printf("n = %d, check2=%d, m=%d\n",n,n+((m-n)/2),m);
            n = n+((m-n)/2);
            //printf("i = %d\n",i);
        }
    }
    probe_answer(m);
}
