#include <stdio.h>
int pick(int arr[], int N,int M, int k,int index){
    //printf("M: %d, k: %d, index: %d\n",M,k,index);
    if(index == N-1){
        int a = (k<=0 && M>=0);
        int b = (k-1<=0 && M-arr[index]>=0);
        return a+b;
    }
    int a = pick(arr, N,M-arr[index],k-1,index+1);
    int b = pick(arr, N,M,k,index+1);   
    // printf("M: %d, k: %d, index: %d\n",M,k,index);
    // printf("a: %d, b: %d\n",a,b);
    return a+b;
}

int main(){
    int k, N, M;
    int arr[30];
    scanf("%d%d%d", &k,&N,&M);
    for(int i=0;i<N;i++)
        scanf("%d", &arr[i]);
    int ways = pick(arr, N,M,k,0);
    printf("%d\n", ways);
    return 0;
}