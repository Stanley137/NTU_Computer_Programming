#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a_1,const void *b_1){
    const int *a = a_1, *b = b_1;
    if(*a > *b)
        return -1;
    else if(*a == *b)
        return 0;
    else
        return 1;
}
int main(){
    int arr[10] = {10, 9, 8, 7, 6 ,5, 4, 3, 2, 1};
    qsort(arr,10,sizeof(int),cmp);
    for(int i=0;i<10;i++)
        printf("%d ", arr[i]);
    return 0;
}