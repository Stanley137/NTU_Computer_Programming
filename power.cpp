#include<stdio.h>
int main(){
    int n, result=1;
    int power;
    scanf("%d", &n);
    scanf("%d", &power);
    for(int i=0;i<power;i++)
        result *= n;
    printf("%d\n", result);
    return 0;
}