#include <stdio.h>
int main(){
    int arr[1000];
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    for(int i=n-1;i>0;i--)
        printf("%d ",arr[i]);
    printf("%d", arr[0]);
    return 0;
}