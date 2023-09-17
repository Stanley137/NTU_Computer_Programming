#include <stdio.h>
int main(){
    int x,y;
    int arr[100][2];
    int xmax=-10000, ymax=-10000;
    int xmin=10000, ymin=10000;
    while(scanf("%d%d",&x,&y)!=EOF){
        if(x > xmax)
            xmax = x;
        if(x < xmin)
            xmin = x;
        if(y > ymax)
            ymax = y;
        if(y < ymin)
            ymin = y;
    }
    int width = xmax - xmin;
    int height = ymax - ymin;
    printf("%d\n",width * height);
    return 0;
}