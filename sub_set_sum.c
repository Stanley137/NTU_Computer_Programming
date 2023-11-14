#include <stdio.h>
int findall(int num,int sum, int k, int arr[30], int n){
    //printf("%d %d %d\n", num,sum,k);
    if(k==n-1){
        if(sum == num)
            return 1;
        else if(sum +arr[k] == num)
            return 1;
        else 
            return 0;
    }
    else{
        int a = findall(num,sum,k+1,arr,n);
        int b = findall(num,sum+arr[k],k+1,arr,n);
        return a+b;
    }
    
}
int main(){
    int n, num;
    scanf("%d", &n);
    int arr[30];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    while(scanf("%d", &num) != EOF){
        int times=0;
        times = findall(num, 0, 0, arr, n);
        printf("%d\n", times);
    }
}