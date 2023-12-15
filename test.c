#include <stdio.h>
struct test
{
    int a;
    int b;
};
typedef struct test test;
int main(){
    test A = {1,2};
    test B;
    B = A;
    printf("%d %d\n",B.a,B.b);
    return  0;
}

