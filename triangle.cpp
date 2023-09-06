#include<stdio.h>
int main(){
    int n, num;
    scanf("%d", &num);
    for(int n = 0; n<num;n++){
        int x1,y1,x2,y2,x3,y3;
        int temp;
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        int d1 = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        int d2 = (x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
        int d3 = (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
        // check for isosceles
        if(d1==d2 || d2==d3 || d1==d3){
            printf("isosceles\n");
            continue;
        }
        // check for right
        if((d1+d2)==d3 || (d2+d3)==d1 || (d1+d3)==d2){
            printf("right\n");
            continue;
        }
        if((d1+d2)>d3 && (d2+d3)<d1 && (d1+d3)<d2)  printf("acute\n");
        else if((d1+d2)>d3 && (d2+d3)<d1 && (d1+d3)<d2)  printf("acute\n");
        else if((d1+d2)>d3 && (d2+d3)<d1 && (d1+d3)<d2)  printf("acute\n");
        else if((d1+d2)>d3 && (d2+d3)>d1 && (d1+d3)>d2)  printf("acute\n");
        else    printf("obtuse\n");
    }
    return 0;
}