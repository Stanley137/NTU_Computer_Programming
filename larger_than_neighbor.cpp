#include <stdio.h>
int is_in_the_bound(int r, int c, int row, int col){
    if((r>row-1)||(r<0)||(c<0)||(c>col-1))
        return 0;
    return 1;
}
int main(){
    int arr[100][100];
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            scanf("%d", &arr[i][j]);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            // printf("%d\n", arr[i][j]);  
            int flag = 0;
            // right
            if(is_in_the_bound(i,j+1,r,c)){
                // printf("h1 ");
                if(arr[i][j] > arr[i][j+1])
                    flag = 1;
                else
                    continue;
            }
            // printf("flag: %d\n", flag);
            // left
            if(is_in_the_bound(i,j-1,r,c)){
                // printf("h1 ");
                if(arr[i][j] > arr[i][j-1])
                    flag = 1;
                else 
                    continue;
            }
            // printf("flag: %d\n", flag);
            // down
            if(is_in_the_bound(i-1,j,r,c)){
                // printf("h1 ");
                if(arr[i][j] > arr[i-1][j])
                    flag = 1;
                else 
                    continue;
            }
            // printf("flag: %d\n", flag);
            // up
            if(is_in_the_bound(i+1,j,r,c)){
                // printf("h1 ");
                if(arr[i][j] > arr[i+1][j])
                    flag = 1;
                else 
                    continue;
            }
            // printf("flag: %d\n", flag);
            if(flag)
                printf("%d\n", arr[i][j]);
        }
    }
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++)
    //         printf("%d ", arr[i][j]);
    //     printf("\n");
    // }
    return 0;
}