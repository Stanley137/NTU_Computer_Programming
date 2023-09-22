#include <stdio.h>
int one_f(int a, int b, int c, int d)
{
    return a + b + c + d;
}
int two_f(int a, int b, int c, int d)
{
    return a * a + b * b + c * c + d * d;
}
int three_f(int a, int b, int c, int d)
{
    return a * a * a + b * b * b + c * c * c + d * d * d;
}
int four_f(int a, int b, int c, int d)
{
    return a * a * a * a + b * b * b * b + c * c * c * c + d * d * d * d;
}
int main()
{
    int one, two, three, four;
    scanf("%d%d%d%d", &one, &two, &three, &four);
    for(int a=one-1;a>1;a--){
        for(int b=a-1;b>1;b--){
            for(int c=b-1;c>1;c--){
                int d = one - a - b- c;
                if(d>=c) // d<1 might cause the loop c can't work,
                    break;// because our a,b,c is too large, d can be negative at the start, but could be positive in the end, so this might escape the root
                if (one_f(a, b, c, d) == one && two_f(a, b, c, d) == two && three_f(a, b, c, d) == three && four_f(a, b, c, d) == four)
                {
                    printf("%d\n%d\n%d\n%d\n", a, b, c, d);
                    return 0;
                }
                printf("%d %d %d %d\n",a,b,c,d);
            }
        }
    }
    printf("-1\n");
    return 0;
}