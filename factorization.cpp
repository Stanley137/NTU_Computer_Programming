#include <stdio.h>
#define up 100000
#define down -100000
int f(int x, int a, int b, int c){
    return x*x*x + a*x*x + b*x + c;
}
int d(int x, int a,int b,int c){ // 判斷重根??
    return 3*x*x + 2*a*x + b*x;
}
int main(){ 
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    // f(x) = x^3 + ax^2 + bx + c
    int h = -a/3, k = f(h,a,b,c);
    int x[3], n = 0;
    if(k==0){ // on axis
        // printf("here0\n");
        x[1] = h;
        for(int i=h-1;i>down;i--){
            if(f(i,a,b,c)==0)
                x[0] = i;
        }
        for(int i=h+1;i<up;i++){
            if(f(i,a,b,c)==0)
                x[2] = i;
        }
    }
    else if(k>0){
        // printf("here1\n");
        n = 1;
        for(int i=h-1;i>down;i--){
            if(f(i,a,b,c)==0)
                x[0] = i;
        }
        for(int i=h+1;i<up;i++){
            if(f(i,a,b,c)==0)
                x[n++] = i;
        }
    }
    else{ // k<0    
        // printf("here2\n");
        n = 1;
        for(int i=h-1;i>down;i--){
            if(f(i,a,b,c)==0)
                x[n--] = i;
        }
        for(int i=h+1;i<up;i++){
            if(f(i,a,b,c)==0)
                x[2] = i;
        }
    }
    printf("%d %d %d\n", -x[2], -x[1], -x[0]);
    return 0;
}