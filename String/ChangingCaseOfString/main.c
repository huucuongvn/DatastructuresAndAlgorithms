#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char A[]="WELCOME";
    int i;
    for(i=0; A[i]!='\0'; i++) {
        A[i]+=32; //ASCII 'a'-'A'=32
    }
    printf("%s\n", A);
    for(i=0; A[i]!='\0'; i++) {
        if(A[i]>=65 && A[i]<=90) {
            A[i]+=32;
        } else if(A[i]>=97 && A[i]<=122) {
            A[i]-=32;
        }
    }

    return 0;
}
