#include <stdio.h>
#include <stdlib.h>

int main()
{
    // using HashTable
    char A[]="AinzZAingzZ";
    int H[53]={0},i;
    for(i=0; A[i]!='\0'; i++) {
        if(A[i]>=97 && A[i]<=122)
            H[A[i]-97]+=1;
        if(A[i]>=65 && A[i]<=90)
            H[A[i]-38]+=1;
    }
    for(i=0; i<53; i++) {
        if(H[i]>1 && i<27)
            printf("%c appearing %d time\n", i+97, H[i]);
        if(H[i]>1 && i>=27)
            printf("%c appearing %d time\n", i+38, H[i]);
    }

    //using bitwise operation
    char B[]="finding";
    long int L=0,x=0;
    for(int i=0; B[i]!='\0'; i++) {
        x=1;
        x <<= B[i]-97;
        if((x&L)>0)
            printf("%c is Duplicate\n", B[i]);
        else
            L = x|L;
    }


    return 0;
}
