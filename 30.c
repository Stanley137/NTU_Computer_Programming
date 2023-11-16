#include <stdio.h>
int way(int arr[20][20], int row, int col){
    if(arr[row][col] == 0 || row<1 || col < 1)
        return 0;
    if((row == 1 && col == 2) ||(row == 2 && col == 1))
        return 1;
    return way(arr,row-1,col) + way(arr,row, col-1);
}
int main(){
    int row, col;
    int arr[20][20];
    scanf("%d%d", &row, &col);
    for(int i=row;i>=1;i--){
        for(int j=1;j<=col;j++)
            scanf("%d", &arr[i][j]);
    }
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++)
    //         printf("%d", arr[i][j]);
    // }
    printf("%d",way(arr, row, col));
    return 0;
}
