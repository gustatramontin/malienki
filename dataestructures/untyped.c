
#include <stdio.h>
#include <stdlib.h>

typedef union {
    int i;
    float f;
    char * str;
} all;


int main() {
   int a = 3;
   all num;
    num.i = a;
    
    //printf("my num %d",  *((int *) num.v));
    printf("my num %d",  num.i);
}
