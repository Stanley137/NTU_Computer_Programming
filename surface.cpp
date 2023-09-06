#include <stdio.h>
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int surface = ((a * b) *2) + ((b * c) * 2) + ((a * c) * 2);
    int volumn = a * b * c;
    printf("%d\n%d\n", surface, volumn);
    return 0;
}