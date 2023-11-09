#include <stdio.h>
int main(){
    long long num;
    while(scanf("%lld", &num) != EOF){
        int sum=0;
        while(num>=1){
            if(num&1)   
                sum++;
            num = num>>1;
        }
        printf("%d\n", sum);
    }
    return 0;
}