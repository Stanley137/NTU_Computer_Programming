#include <stdio.h>
int square_sum(int n){
    if(n==1)
        return 1;
    else
        return n*n + square_sum(n-1);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", square_sum(n));
    return 0;
}