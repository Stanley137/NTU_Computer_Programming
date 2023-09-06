#include <stdio.h>
int main(){
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, 
        &x3, &y3, &x4, &y4);
    int c1, c2, c3, c4;
    c1 = (x1 * y2) - (y1 * x2);
    c2 = (x2 * y3) - (y2 * x3);
    c3 = (x3 * y4) - (y3 * x4);
    c4 = (x4 * y1) - (y4 * x1);
    ((c1 > 0) && (c2 > 0) && (c3 > 0) && (c4 > 0)) ? printf("1") : printf("0");
    return 0;
}