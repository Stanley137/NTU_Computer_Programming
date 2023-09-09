#include <stdio.h>
void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int num;
    scanf("%d", &num);
    for(int n = 0;n<num;n++){
        int x1,y1,x2,y2,x3,y3,x4,y4;
        scanf("%d%d%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        int v1x = (x2-x1), v1y = (y2-y1);
        int v2x = (x3-x1), v2y = (y3-y1);
        int v3x = (x4-x1), v3y = (y4-y1);
        int det = (v1x*v2y) - (v1y*v2x);
        if(det < 0){ // determind 1, 2, 3
            swap(&x3,&x2);
            swap(&y3,&y2);
        }
        v1x = (x2-x1), v1y = (y2-y1);
        v2x = (x3-x1), v2y = (y3-y1);
        v3x = (x4-x1), v3y = (y4-y1);
        det = (v1x*v3y) - (v1y*v3x);
        if(det < 0){ // check for 1,(4) 2, 3
            swap(&x4, &x2);
            swap(&y4, &y2);
            swap(&x4, &x3);
            swap(&y4, &y3);
        }
        else{
            det = (v2x*v3y) - (v2y*v3x);
            if(det < 0){ // check for 1,2, (4), 3
                swap(&x4, &x3);
                swap(&y4, &y3);
            }
        }
        v1x = (x2-x1), v1y = (y2-y1);
        v2x = (x3-x2), v2y = (y3-y2);
        v3x = (x4-x3), v3y = (y4-y3);
        int v4x = (x1-x4), v4y = (y1-y4);
        int v5x = (x3-x1), v5y = (y3-y1);
        int v6x = (x4-x2), v6y = (y4-y2);
        int d1 = v1x*v1x + v1y*v1y;
        int d2 = v2x*v2x + v2y*v2y;
        int d3 = v3x*v3x + v3y*v3y;
        int d4 = v4x*v4x + v4y*v4y;
        int d5 = v5x*v5x + v5y*v5y;
        int d6 = v6x*v6x + v6y*v6y;
        if(d1==d2 && d2==d3 && d3==d4){
            if(d1+d2==d5 && d2+d3==d6 && d3+d4==d5)
                printf("square\n");
            else
                printf("diamond\n");
        }
        else{
            if(d1+d2==d5 && d2+d3==d6 && d3+d4==d5)
                printf("rectangle\n");
            else
                printf("other\n");
        }
    }
}