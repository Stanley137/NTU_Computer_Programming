#include <stdio.h>
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void sort(int arr[], int N){
    for(int i=N-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(arr[j]>arr[j+1])
                swap(arr, j,j+1);
        }
    }
}
void permu(int arr[],int bool[] ,int N, int k){
    if(k==0){
        printf("\n");
        return; 
    }
    for(int i=0;i<N;i++){
        if(!bool[i]){
            printf("%d ", arr[i]);
            bool[i] = 1;
            printf("bool: ");
            for(int j=0;j<N;j++) printf("%d ", bool[j]);
            printf("\n");
            permu(arr, bool, N,N-1);
            bool[i] = 0;
        }
    }
}
int main(){
    int N, arr[10], bool[10] = {0};
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d", &arr[i]);
    sort(arr, N);
    //for(int i=0;i<N;i++) printf("%d ", arr[i]);
    permu(arr, bool, N, N);
    return 0;
}