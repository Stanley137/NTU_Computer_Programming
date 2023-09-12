#include <stdio.h>
#include <stdlib.h>
int main(){
    int *data, *remainder;
    int n, m;
    scanf("%d", &n);
    data = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", &data[i]);
    scanf("%d", &m);
    remainder = (int *)malloc(m * sizeof(int));
    for(int i=0;i<m;i++) remainder[i] = 0;
    for(int i=0;i<n;i++){
        int index = data[i] % m;
        remainder[index]++;
    }
    for(int i=0;i<m;i++) printf("%d\n", remainder[i]);
    return 0;
}