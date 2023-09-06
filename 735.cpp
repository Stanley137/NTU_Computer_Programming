#include <stdio.h>
int main(){
    int x;
    scanf("%d", &x);
    (x % 15 ==0 && x % 7 != 0) ? printf("0") : printf("1");
    return 0; 
}