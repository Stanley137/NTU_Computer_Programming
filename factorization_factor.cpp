#include <stdio.h>
#include <math.h>
long double func(long double x,int a, int b,int c){
    return x*x*x + a*x*x + b*x + c;
}
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int x1 = -10000;    
    while(func(x1,a,b,c)!=0){
        // printf("%d\n",x1);  
        x1++;
    } 
    // x^2 + px + q = 0
    int p = (a+x1), q = b + a*x1+x1*x1;
    // printf("%d %d\n",p,q);
    // printf("%f\n",sqrt(p*p-4*p));
    int x2 = (-p-sqrt((p*p-4*q)))/2;
    int x3 = (-p+sqrt((p*p-4*q)))/2;
    if(b == 0 && c == 0 && a>0){
        x1 = -a;
        x2 = 0;
        x3 = 0;
    }
    printf("%d %d %d\n",-x3,-x2,-x1);
    // printf("%d %d %d\n",func(x1,a,b,c),func(x2,a,b,c),func(x3,a,b,c));
    return 0;
}