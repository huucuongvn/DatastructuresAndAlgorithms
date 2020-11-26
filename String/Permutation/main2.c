#include <stdio.h>
#include <stdlib.h>

void swap(char *x, char *y) {
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void perm(char s[],int left, int right) {
    int i;
    if(left==right) {
        printf("%s\n", s);
    } else {
        for(i=left; i<=right; i++) {
            swap(&s[left], &s[i]);
            perm(s, left+1, right);
            swap(&s[left], &s[i]);
        }
    }
}

int main()
{
    char s[]="ABC";
    perm(s, 0, 2);
    return 0;
}
