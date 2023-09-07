#include<stdio.h>
int main(){
    int num;
    scanf("%d", &num);
    for(int n = 0;n<num;n++){
        int x1,y1,x2,y2,x3,y3,x4,y4;
        int temp;
        scanf("%d%d%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        // determine the circle, p3 is diagnose
        int v1x = (x2-x1), v1y = (y2-y1);
        int v2x = (x3-x1), v2y = (y3-y1);
        int v3x = (x4-x1), v3y = (y4-y1);
        int det_a = (v1x*v2y) - (v1y*v2x);
        int det_b = (v1x*v3y) - (v1y*v3x);
        if(det_a * det_b < 0){ // p2 is diag
            temp = x2;
            x2 = x3;
            x3 = temp;
            temp = y2;
            y2 = y3;
            y3 = temp;
        }
        else{
            det_a = (v2x*v1y) - (v2y*v1x);
            det_b = (v2x*v3y) - (v2y*v3x);
            if(!(det_a * det_b < 0)){ // p3 is diag or p4
                // p3 <> p4
                temp = x3;
                x3 = x4;
                x4 = temp;
                temp = y3;
                y3 = y4;
                y4 = temp;
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
    return 0;
}