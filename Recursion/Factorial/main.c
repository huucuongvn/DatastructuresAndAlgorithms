#include <stdio.h>
#include <stdlib.h>

int fact(int n) {
    if(n==0) {
        return 1;
    } else {
        return fact(n-1)*n;
    }
}

int main()
{
    int a;
    a=fact(5);
    printf("%d",a);
    return 0;
}
