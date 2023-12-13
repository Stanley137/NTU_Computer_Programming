#include <stdio.h>
int find_balance(int T[],int N){
    for(int i=0;i<N;i++){
        int sum = 0;
        for(int j=0;j<i;j++)
            sum += ((j-i) * T[j]);
        for(int j=i+1;j<N;j++)
            sum += ((j-i) * T[j]);
        if(sum == 0)
            return i;
    }
    return -1;
}
int main(){
    int n;
    int arr[100];
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("%d\n", find_balance(arr, n));
    return 0;
}