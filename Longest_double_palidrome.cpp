#include <stdio.h>
int main(){
    int arr[100], i=0;
    while(scanf("%d",&arr[i++])!=EOF){}
    printf("%d\n",i);
    for(int j=0;j<i;j++){
        printf("[%d,%d] %d ",j,i, arr[j]);
    }
    return 0;
}