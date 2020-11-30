#include <stdio.h>
#include <stdlib.h>

int main()
{
    // using method 1
    char A[]="python";
    char B[7];
    int i,j;
    for(i=0; A[i]!='\0'; i++) {}
    i--;
    for(j=0; i>=0; i--, j++) {
        B[j]=A[i];
    }
    B[j]='\0';
    printf("%s\n", B);

    // using method 2
    char C[]="operation";
    int m,n;
    char t;
    for(m=0; C[m]!='\0'; m++) {}
    m--;
    for(n=0; n<m; n++, m--) {
        t=C[n];
        C[n]=C[m];
        C[m]=t;
    }
    printf("%s\n", C);

    return 0;	
}
