#include<stdio.h>
int main(){
    int n, m;
    int A = 0, B = 0;
    scanf("%d %d", &n, &m);
    // determine A, then B
    int num1 = n, num2 = m, num3 = m;
    for(int i=0;i<4;i++){
        int digit1 = num1 % 10, digit2 = num2 % 10;
        if(digit1 == digit2)
            A++;
        num3 = m;
        for(int j = 0;j<4;j++){
            int digit2 = num3 % 10;
            if(digit1 == digit2)
                B++;
            num3 /= 10; 
        }
        num1 /= 10;
        num2 /= 10;
    }
    B = B - A;
    printf("%dA%dB\n", A, B);
    return 0;
}