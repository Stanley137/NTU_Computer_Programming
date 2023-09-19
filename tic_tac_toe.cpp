#include <stdio.h>
#include <stdbool.h>
bool check_move(int x, int y, int game[3][3]){
    if(x>=0 && x<=2 && y>=0 && y<=2 && (game[x][y]==0))
        return 1;
    else 
        return 0;
}
int check_win(int game[3][3]){
    // check horizon
    for(int y=2;y>=0;y--){
        int count = 0;
        for(int x=0;x<3;x++){
            if(game[x][y] == 1)
                count++;
            else if(game[x][y] == -1)
                count--;
        }
        if(count == 3)
            return 1;
        else if(count == -3)
            return -1;
    }
    // check vertic
    for(int x=0;x<3;x++){
        int count = 0;
        for(int y=0;y<3;y++){
            if(game[x][y] == 1)
                count++;
            else if(game[x][y] == -1)
                count--;
        }
        if(count==3)
            return 1;
        else if(count==-3)
            return -1;
    }
    // check diag
    if(game[0][0] == 1 && game[1][1]==1 && game[2][2]==1)
        return 1;
    else if(game[0][0] == -1 && game[1][1]==-1 && game[2][2]==-1)
        return -1;
    else if(game[0][2] == 1 && game[1][1]==1 && game[2][0]==1)
        return 1;
    else if(game[0][2] == -1 && game[1][1]==-1 && game[2][0]==-1)
        return -1;
    // nothing 
    return 0;
}

int main(){
    int game[3][3] = {0};
    int N, v = 0;
    int x,y;
    scanf("%d", &N);
    for(int n = 0;n<N;n++){
        scanf("%d%d",&x,&y);
        if(check_move(x,y,game)){
            if(v%2==0)
                game[x][y] = 1; // 1, black
            else
                game[x][y] = -1; // -1, white
            v++;
            if(check_win(game)==1){
                printf("Black wins.");
                return 0;
            }
            else if(check_win(game)==-1){
                printf("White wins.");
                return 0;
            }
        }
        else
            continue;
    }
    printf("There is a draw.");
        // // visualize
        // for(int y=2;y>=0;y--){
        //     for(int x=0;x<3;x++)
        //         printf("%d ",game[x][y]);
        //     printf("\n");
        // 
    return 0;
}