#include <stdio.h>
#include <stdlib.h>
int main(){
    int r, c, arr[100][100];
    scanf("%d %d", &r,&c);
    int *column_sum = (int *)malloc(c * sizeof(int));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            scanf("%d", &arr[i][j]);
    }
    for(int i=0;i<c;i++){
        // printf("hi");
        int column = 0;
        for(int j=0;j<r;j++)
            column += arr[j][i];
        printf("%d\n", column/r);    
    }
    return 0;
}