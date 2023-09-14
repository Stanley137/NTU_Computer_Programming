#include <stdio.h>
int check_wall(int x1, int y1, int X, int Y){
    if(x1==X || x1==1 || y1==Y || y1==1)
        return 1;
    return 0;
}
void swap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = *a;
}
int main(){
    int box[301][301] = {0};
    int X, Y;
    int x1,y1,x2,y2;
    int dx1,dy1,dx2,dy2;
    int times;
    scanf("%d%d", &X, &Y);
    scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
    scanf("%d%d%d%d", &dx1,&dy1,&dx2,&dy2);
    scanf("%d", &times);
    // init the box
    for(int i=1;i<=X;i++){
        box[i][1] = 1;
        box[i][Y] = 1;
    }
    for(int j=1;j<=Y;j++){
        box[1][j] = 1;
        box[X][j] = 1;
    }
    for(int t=0;t<times;t++){
        // ball_1 move
        x1 += dx1;
        y1 += dy2;
        if(check_wall(x1,y1,X,Y)){
            // which wall
            if((x1==1 && y1==1) || (x1==1 && y1==Y) ||
               (x1==X && y1==1) || (x1==X && y1==Y)){
                dx1 = -dx1;
                dy1 = -dy1;
            }
            else if(x1==X || x1==1) // right || left
                dx1 = -dx1;
            else if(y1==Y || y1==1) // up || down
                dy1 = -dy1;
        }
        else if((x1)==x2 && (y1)==y2){ // exchange position
            swap(&dx1,&dx2);
            swap(&dy1,&dy1);
        }
        // ball_2 move
        
        // visualize
        // for(int j=Y;j>=1;j--){
        //     for(int i=1;i<=X;i++)
        //         printf("%d ",box[i][j]);
        //     printf("\n");
        // }
        // printf("\n---------\n");
    }
    // printf("%d %d\n", X,Y);
    // swap(&x2,&y2);
    // printf("%d %d\n", x2,y2);
    // printf("%d %d %d %d\n",x1,y1,x2,y2);
    // printf("%d %d %d %d\n", dx1,dy1,dx2,dy2);
    // for(int j=Y;j>=1;j--){
    //     for(int i=1;i<=X;i++)
    //         printf("%d ",box[i][j]);
    //     printf("\n");
    // }
    return 0;
}