#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check(int row, int col){
    if(row == 0 && col >=0 && col < 10)
        return 1;
    else if(row == 1 && col >=0 && col < 9)
        return 1;
    else if(row == 2 && col >= 0 && col < 7)
        return 1;
    return 0;
}
void findkey(int *row, int *col,char board[3][15], char init_pos){
    char *find = NULL;
    int _row, _col;
    for (int i = 0; i < 3; i++)
    {
        find = strchr(board[i], init_pos);
        if (find != NULL)
        {
            _row = i;
            _col = find - board[i];
                break;
        }
    }
    *row = _row;
    *col = _col;
}
int main(){
    char board[3][15] = {"qwertyuiop","asdfghjkl","zxcvbnm"};
    char init_pos[3];
    int key;
    int row, col;
    int row_table[6] = {0, -1, -1, 0, 1, 1};
    int col_table[6] = {1, 1, 0, -1, -1, 0};
    scanf("%s", init_pos);
    printf("%c\n", init_pos[0]);
    findkey(&row,&col,board,init_pos[0]);
    while(scanf("%d", &key) != EOF){
        int index = key;
        if(check(row+row_table[index], col+col_table[index])){
            row += row_table[index];
            col += col_table[index];
            // printf("--\n%c\n--\n", board[row][col]);
            printf("%c\n", board[row][col]);
        }
        else
            continue;
    }
    // printf("%d %d\n", row, col);
    return 0;
}