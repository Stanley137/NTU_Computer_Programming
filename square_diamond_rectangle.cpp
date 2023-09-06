#include<stdio.h>
int main(){
    int num;
    scanf("%d", &num);
    for(int n = 0;n<num;n++){
        int x1,y1,x2,y2,x3,y3,x4,y4;
        scanf("%d%d%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        // determine the circle
        int v1, v2 ,v3;
        int d1 = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        int d2 = (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
        int d3 = (x1-x4)*(x1-x4)+(y1-y4)*(y1-y4);
        int d4 = (x2-x4)*(x2-x4)+(y2-y4)*(y2-y4);
        int d5 = (x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
        int d6 = (x3-x4)*(x3-x4)+(y3-y4)*(y3-y4);
        
        
    }
}