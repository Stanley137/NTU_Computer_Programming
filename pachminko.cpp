#include <stdio.h>
#include <stdlib.h>
int main(){
    int N;
    scanf("%d",&N);
    N=N*(N+1)/2;
    int *arr_h = (int *)malloc(sizeof(int) * N);
    int *arr_l = (int *)malloc(sizeof(int) * N);
    int *arr_r = (int *)malloc(sizeof(int) * N);
}