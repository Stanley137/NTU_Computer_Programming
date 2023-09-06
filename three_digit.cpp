#include<stdio.h>
int main(){
    int num;
    scanf("%d", &num);
    int dig_0, dig_1, dig_2;
    dig_0 = num % 10;
    dig_1 = (num / 10) % 10;
    dig_2 = (num / 100) % 10;
    printf("%d\n%d\n%d", dig_2, dig_1, dig_0);
    return 0;
}