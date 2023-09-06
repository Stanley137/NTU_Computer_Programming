#include <stdio.h>
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int flag = ((a + b > c) && (b + c) > a && (a + c) > b) ? 1 : 0;
    printf("%d", flag);
    return 0;
}