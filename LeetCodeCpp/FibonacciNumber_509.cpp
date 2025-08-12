#include "FibonacciNumber_509.h"

int FibonacciNumber_509::fib(int n)
{
    if (n <= 1) return n;     // F(0)=0, F(1)=1
    int a = 0, b = 1;         // a=F(0), b=F(1)
    for (int i = 2; i <= n; ++i) {
        int c = a + b;        // c=F(i)
        a = b;
        b = c;
    }
    return b;                 // F(n)
}