#include <stdio.h>
int check_wall(int x1, int y1, int X, int Y){
    if(x1==X || x1==1 || y1==Y || y1==1)
        return 1;
    return 0;
}
void swap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    // int box[301][301] = {0};
    int X, Y;
    int x1,y1,x2,y2;
    int dx1,dy1,dx2,dy2;
    int times;
    scanf("%d%d", &X, &Y);
    scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
    scanf("%d%d%d%d", &dx1,&dy1,&dx2,&dy2);
    scanf("%d", &times);
    for(int t=0;t<times;t++){
        // ball_1 move
        if(check_wall(x1,y1,X,Y) && x1==x2 && y1==y2){
            if (x1 == X || x1 == 1) // right || left
                dx1 = -dx1;
            if (y1 == Y || y1 == 1) // up || down
                dy1 = -dy1;
            swap(&dx1,&dx2);
            swap(&dy1,&dy2);
        }
        else if(check_wall(x1,y1,X,Y)){
            // which wall
            // if((x1==1 && y1==1) || (x1==1 && y1==Y) ||
            //    (x1==X && y1==1) || (x1==X && y1==Y)){
            //     dx1 = -dx1;
            //     dy1 = -dy1;
            //}
            if(x1==X || x1==1) // right || left
                dx1 = -dx1;
            if(y1==Y || y1==1) // up || down
                dy1 = -dy1;
        }
        else if((x1)==x2 && (y1)==y2){ // exchange position
            // printf("Swap1\n");
            swap(&dx1,&dx2);
            swap(&dy1,&dy2);
            // printf("%d %d\n",dx1,dy1);
            // printf("%d %d\n",dx2,dy2);
        }
        x1 += dx1;
        y1 += dy1;
        printf("%d %d\n", x1,y1);
        // printf("%d %d\n",dx1,dy1);
        // ball_2 move
        if(check_wall(x2,y2,X,Y) && x1==x2 && y1==y2){
            if(x2==X || x2==1)
                dx2 = -dx2;
            if(y2==Y || y2==1)
                dy2 = -dy2;
            swap(&dx1,&dx2);
            swap(&dy1,&dy2);
        }
        else if(check_wall(x2,y2,X,Y)){
            // which wall
            // if((x2==1 && y2==1) || (x2==1 && y2==Y) ||
            //    (x2==X && y2==1) || (x2==X && y2==Y)){
            //     dx2 = -dx2;
            //     dy2 = -dy2;          
            // }
            if(x2==X || x2==1)
                dx2 = -dx2;
            if(y2==Y || y2==1)
                dy2 = -dy2;
        }
        else if(x1==x2 && y1==y2){
            // printf("Swap2\n");
            swap(&dx1,&dx2);
            swap(&dy1,&dy2);
        }
        x2 += dx2;
        y2 += dy2;
        printf("%d %d\n", x2,y2);
        // printf("%d %d\n",dx2,dy2);
    }
    printf("%d\n%d\n%d\n%d\n", x1,y1,x2,y2);
    // printf("%d %d\n", X,Y);
    // swap(&x2,&y2);
    // printf("%d %d\n", x2,y2);
    // printf("%d %d %d %d\n",x1,y1,x2,y2);
    // printf("%d %d %d %d\n", dx1,dy1,dx2,dy2);
    return 0;
}