#include <stdio.h>
int main(){
    int num;
    while(scanf("%d", &num)!=EOF){
        int max = -1, sum=0;
        while(num>=1){
            if(num&1){
                sum++;
                if(sum > max)
                    max = sum;
            }
            else
                sum=0;
            num = num>>1;
        }
        printf("%d\n", max);
    }
}