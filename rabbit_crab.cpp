#include <stdio.h>
int main(){
    unsigned int s, f, t;
    int chicken, rabbit, crab;
    scanf("%d%d%d", &s, &f, &t);
    crab = (s - t);
    rabbit = (((float)f/2 - (float)4*s + (float)3*t)) == ((f/2 - 4*s + 3*t)) ? ((f/2 - 4*s + 3*t)) : -1;
    chicken = (s - rabbit - crab);
    if(chicken < 0 || rabbit < 0 || crab < 0)
        printf("0");
    else
        printf("%d\n%d\n%d",chicken, rabbit, crab); 
    return 0;
}