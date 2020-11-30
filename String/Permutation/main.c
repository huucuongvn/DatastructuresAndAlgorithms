#include <stdio.h>
#include <stdlib.h>

void swap(char *x, char *y) {
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void perm1(char s[],int left, int right) {
    int i;
    if(left==right) {
        printf("%s\n", s);
    } else {
        for(i=left; i<=right; i++) {
            swap(&s[left], &s[i]);
            perm1(s, left+1, right);
            swap(&s[left], &s[i]);
        }
    }
}

void perm2(char s[], int k) {
    static int A[10]={0};
    static char res[10];
    int i;
    if(s[k]=='\0') {
        res[k]='\0';
        printf("%s\n", res);
    } else {
        for(i=0; s[i]!='\0'; i++) {
            if(A[i]==0) {
                res[k]=s[i];
                A[i]=1;
                perm2(s, k+1);
                A[i]=0;
            }
        }
    }
}

int main()
{
    char d[]="ABCD";
    perm1(d, 0, 3);
    char s[]="ABC";
    perm2(s,0);


    return 0;
}
