#include<stdio.h>
int gcd(int x, int y){
    while(x % y != 0){
        int remainder = x % y;
        x = y;
        y = remainder; 
    }
    return y;
}
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    int GCD = (a > b ? gcd(a, b) : gcd(b, a));
    printf("%d", GCD);
    return 0;
}