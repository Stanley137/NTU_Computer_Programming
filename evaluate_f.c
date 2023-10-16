#include <stdio.h>
#include <limits.h>
int func(int x,int y){
    return 4*x - 6*y;
}
int evaluate_f(int *iptr[], int n, int *index){
    // find the maximun values
    int max = INT_MIN;
    int x, y;
    int value;
    for(int i=0;i<n;i++){
        int * arr = iptr[i];
        x = arr[0];
        y = arr[1];
        value = func(x, y);
        if(value > max){
            max = value;
            *index = i; 
        }
    }
    return max;
}