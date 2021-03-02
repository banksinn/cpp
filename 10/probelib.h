#include <bits/stdc++.h>
using namespace std;

static int n;
static int target;
static int counter;

#define MAX_PROBE 22

static void probe_error(const char* msg)
{
    cout << "ERROR: " <<  msg << "\n";
    exit(0);
}

int probe_init()
{
    cin >> n >> target;
    counter = 0;
    return n;
}

bool probe_check(int a, int b)
{
    if((a < 0) || (a > b) || (b > n-1)) {
        probe_error("out of range");
    }
    counter++;
    if(counter > MAX_PROBE) {
        probe_error("too many checks");
    }
    return (target >= a) && (target <= b);
}

void probe_answer(int answer)
{
    if(answer == target) {
        cout << "Correct" << "\n";
    } else {
        cout << "Incorrect" << "\n";
    }
    exit(0);
}
