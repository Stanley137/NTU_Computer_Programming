#include <stdio.h>
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int num = m ,ret = 0;
    while(num != 0){
        int digits2 = num % 100;
        if(digits2 == n)    ret++;
        num /= 10;
    }
    printf("%d\n", ret);
    return 0;
}