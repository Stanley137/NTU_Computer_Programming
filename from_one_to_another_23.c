#include <stdio.h>
int way(int row, int col){
    if(row == 1 || col == 1)
        return 1;
    return way(row-1,col) + way(row, col-1);
}
int main(){
    int row, col;
    printf("%d", way(row, col));
    return 0;
}