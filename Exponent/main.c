#include <stdio.h>
#include <stdlib.h>

int exponent(int m,int n) {
    if(n==0) {
        return 1;
    } else if((n%2)==0) {
        return exponent(m*m,n/2);
    } else {
        return m*exponent(m*m,(n-1)/2);
    }
}

int main()
{
    int a;
    a=exponent(3,4);
    printf("%d",a);
    return 0;
}
