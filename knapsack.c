#include <stdio.h>
#include <limits.h>
struct object
{
    int w;
    int v;
};
typedef struct object Obj;
int max(int a,int b){
    if(a>b)
        return a;
    else 
        return b;
}
int knapsack(Obj obj[], int W, int n,int k){
    if(k>=n)
        return 0;
    if(W>=obj[k].w)
        return max(knapsack(obj,W-obj[k].w,n,k+1)+obj[k].v,knapsack(obj,W,n,k+1));
    return knapsack(obj,W,n,k+1); // find the next object
}
int main(){
    int n, W;
    Obj obj[20];
    scanf("%d%d", &n,&W);
    for(int i=0;i<n;i++)
        scanf("%d%d", &obj[i].w,&obj[i].v);
    printf("%d\n", knapsack(obj,W,n,0));
    return 0;
}