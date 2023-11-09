#include <stdio.h>
int main(){
    int num;
    while(scanf("%d", &num) != EOF){
        int sum=0;
        while(num >= 1){ // use n & 1
            sum += num%2;
            num /= 2;
        }
        printf("%d\n", sum);
    }
    return 0;
}