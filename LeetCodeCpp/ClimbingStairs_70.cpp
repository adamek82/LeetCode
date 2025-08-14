#include "ClimbingStairs_70.h"

int ClimbingStairs_70::climbStairs(int n)
{
    if (n <= 2) return n;     // Ways(1)=1, Ways(2)=2
    int a = 1, b = 2;         // a=Ways(1), b=Ways(2)
    for (int i = 3; i <= n; ++i) {
        int c = a + b;        // c=Ways(i)
        a = b;
        b = c;
    }
    return b;                 // Ways(n)
}