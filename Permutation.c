#include <stdio.h>
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void sort(int arr[],int head ,int N){
    for(int i=N-2;i>=0;i--){
        for(int j=head;j<=i;j++){
            if(arr[j]>arr[j+1])
                swap(arr, j,j+1);
        }
    }
}
void copy_arr(int dst[],int cpy[], int N){
    for(int i=0;i<N;i++)
        dst[i] = cpy[i];
}
void permu(int arr[],int N, int head){
    //printf("head: %d\n",head);
    int temp[10];
    if(head==N){
        for(int i=0;i<N;i++)    printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for(int i=head;i<N;i++){
        swap(arr,head,i);
        copy_arr(temp,arr,N); // snapshot
        sort(arr,head+1,N);
        permu(arr, N, head+1);
        copy_arr(arr,temp,N); // use again
        swap(arr,head,i);   
    }
}
int main(){
    int N, arr[10], temp[10] = {0};
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d", &arr[i]);
    sort(arr, 0,N);
    //for(int i=0;i<N;i++) printf("%d ", arr[i]);
    permu(arr,N, 0);
    return 0;
}