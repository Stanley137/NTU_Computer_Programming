#include <stdio.h>
int main(){
    int w, a, b, c, d, e;
    scanf("%d%d%d%d%d%d", &w , &a, &b, &c, &d, &e);
    int distance_square, width;
    if(b==0)    width = (e<d) ? (a+d+1+(d-e)+1+e+c):(a+d+1+(e-d)+1+e+c);
    else    width = (a + 2*d + 2*e + 2 + b + c);
    distance_square = width * width + w * w;
    printf("%d", distance_square);
    return 0;
}   