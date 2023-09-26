#include<stdio.h>
#define DEBUG
int gcd(int a,int b){
    int x = a>b? a:b;
    int y = a>b? b:a;
    int r;
    while(x % y !=0){
        r = x % y;
        x = y;
        y = r;
    }
    return y;
}
int lcm(int a, int b){
    int g = gcd(a,b);
    return (a/g) * b; 
}
void dump_pin(int row, int col, int pins[16][16][3][2]){
    printf("row: %d, col: %d\n", row, col);
    printf("left: %d/%d, right: %d/%d\n",pins[row][col][0][0],pins[row][col][0][1],pins[row][col][1][0],pins[row][col][1][1]);
    printf("head: %d/%d\n", pins[row][col][2][0],pins[row][col][2][1]);
}
void factorize(int row,int col,int pins[16][16][3][2]){
    // simplify the factor
    int moth = pins[row][col][0][0] + pins[row][col][1][0];
    pins[row][col][0][1] = moth;
    pins[row][col][1][1] = moth;
    // left
    int gcd1 = gcd(moth, pins[row][col][0][0]);
    pins[row][col][0][0] /= gcd1;
    pins[row][col][0][1] /= gcd1;
    // right
    int gcd2 = gcd(moth, pins[row][col][1][0]);
    pins[row][col][1][0] /= gcd2;
    pins[row][col][1][1] /= gcd2;

}
void cal_pos(int row, int col, int pins[16][16][3][2]){
    if(row-1<0){
        pins[row][col][2][0] = 1; pins[row][col][2][1] = 1;
    } // check up 
    else if(col-1<0){  // check left
        pins[row][col][2][0] = pins[row-1][col][0][0];
        pins[row][col][2][1] = pins[row-1][col][0][1];
    }
    else if(col+1>row){ // check right
        pins[row][col][2][0] = pins[row-1][col-1][1][0];
        pins[row][col][2][1] = pins[row-1][col-1][1][1];
    }
    else{ // normal
        int left_son = pins[row-1][col-1][1][0];
        int left_moth =  pins[row-1][col-1][1][1];
        int right_son = pins[row-1][col][0][0];
        int right_moth = pins[row-1][col][0][1];
        int l = lcm(left_moth, right_moth);
        left_son = left_son * (l/left_moth);
        right_son = right_son * (l/right_moth);
        int sum_son = left_son + right_son;
        int g = gcd(sum_son, l);
        //printf("%d/%d\n", sum_son, l);
        sum_son /= g;
        l /= g;
        #ifdef DEBUG
            printf("Check r:%d c:%d\n", row,col);
            dump_pin(row-1,col-1,pins);
            dump_pin(row-1, col, pins);
        #endif
        pins[row][col][2][0] = sum_son;
        pins[row][col][2][1] = l;
    }
    // calculate left
    int l_son = pins[row][col][0][0];
    int l_moth = pins[row][col][0][1];
    int h_son = pins[row][col][2][0]; 
    int h_moth = pins[row][col][2][1];
    // (l_son/l_moth) * (h_son/h_moth)
    int g1 = gcd(l_son, h_moth);
    l_son /= g1; h_moth /= g1;
    int g2 = gcd(h_son, l_moth);
    h_son /= g2; h_son /= g2;
    pins[row][col][0][0] = l_son * h_son;
    pins[row][col][0][1] = l_moth * h_moth;
    // calculate right
    int r_son = pins[row][col][1][0];
    int r_moth = pins[row][col][1][1];
    h_son = pins[row][col][2][0]; 
    h_moth = pins[row][col][2][1];
    // (r_son/r_moth) * (h_son * h_moth)
    g1 = gcd(r_son, h_moth); 
    r_son /= g1; h_moth /= g1;
    g2 = gcd(h_son, r_moth);
    h_son /= g2; r_moth /= g2;
    pins[row][col][1][0] = r_son * h_son;
    pins[row][col][1][1] = r_moth * h_moth;
}
int main(){
    int pins[16][16][3][2];
    int N;
    scanf("%d",&N);
    for(int row=0;row<N;row++){
        for(int col=0;col<=row;col++){
            scanf("%d%d",&pins[row][col][0][0],&pins[row][col][1][0]);
            factorize(row,col,pins);
        }
    }
    for(int row=0;row<N+1;row++){
        for(int col=0;col<=row;col++)
            cal_pos(row,col,pins);
    }
    for(int row=N,col=0;col<=row;col++)
        printf("%d/%d\n",pins[row][col][2][0], pins[row][col][2][1]);
    // print debug
    #ifdef DEBUG
    for(int row=0;row<N;row++){
        for(int col=0;col<=row;col++)
            printf("%d %d ",pins[row][col][1][0], pins[row][col][1][1]);
        printf("\n");
    }
    #endif
    return 0;
}