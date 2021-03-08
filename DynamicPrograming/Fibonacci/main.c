#include <stdio.h>
#include <stdlib.h>
#define NTL -1
#define MAX 100

//using Tabulation(Bottom Up)
int tfib(int n) {
    int f[n+1];
    f[0]=0;
    f[1]=1;
    for(int i=2; i<=n; i++) {
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

//using Memoization(Top Down)
int lookup[MAX];
void initialize() {
    for(int i=0; i<MAX; i++)
        lookup[i]=NTL;
}
int mfib(int n) {
    if(lookup[n]==NTL) {
        if(n<=1)
            lookup[n]=n;
        else
            lookup[n] = mfib(n-1) + mfib(n-2);
    }
    return lookup[n];
}

int main()
{
    int n=9;
    initialize();
    printf("Fibonacci number is %d ", mfib(n));
    return 0;
}
