#include <stdio.h>
int main(){
    int result[200] = {0};
    int f[100], g[100];
    int n, m;
    scanf("%d", &n);
    for(int i=n-1;i>=0;i--) 
        scanf("%d", &f[i]);
    scanf("%d", &m);
    for(int i=m-1;i>=0;i--)
        scanf("%d",&g[i]);
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--)
            result[i+j] += f[i] * g[j];
    }
    printf("%d", result[m-1+n-1]);
    for(int i = (m-1)+(n-1)-1; i>=0;i--)
        printf(" %d", result[i]);
    return 0;
}