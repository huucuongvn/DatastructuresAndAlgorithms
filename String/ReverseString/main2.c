#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[]="python";
    int i,j;
    char t;
    for(i=0; A[i]!='\0'; i++) {}
    i--;
    for(j=0; j<i; j++, i--) {
        t=A[j];
        A[j]=A[i];
        A[i]=t;
    }
    printf("%s", A);
    return 0;
}
