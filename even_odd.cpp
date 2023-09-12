#include <stdio.h>
#define limit 1000
int main(){
    int arr[limit], first_even, first_odd;
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            first_even = i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]%2==1){
            first_odd = i;
            break;
        }
    }
    printf("%d", arr[first_odd]);
    for(int i=first_odd+1;i<n;i++){
        if(arr[i]%2==1)
            printf(" %d", arr[i]);
    }
    printf("\n");
    printf("%d",arr[first_even]);
    for(int i=first_even+1;i<n;i++){
        if(arr[i]%2==0)
            printf(" %d", arr[i]);
    }
    return 0;
}