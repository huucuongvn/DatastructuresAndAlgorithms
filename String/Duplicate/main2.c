#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//using bitwise operation
int main()
{
    char A[]="finding";
    long int H=0,x=0;
    for(int i=0;A[i]!='\0'; i++) {
        x=1;
        x <<= A[i]-97;
        if((x&H)>0)
            printf("%c is Duplicate\n", A[i]);
        else
            H = x|H;
    }
    return 0;
}
