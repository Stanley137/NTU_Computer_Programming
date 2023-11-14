#include <stdio.h>
struct object
{
    int w;
    int v;
};
typedef struct object Obj;
int knapsack(Obj obj[], int W, int n,int value,int weight){

}

int main(){
    int n, W;
    Obj obj[20];
    scanf("%d%d", &n,&W);
    for(int i=0;i<n;i++)
        scanf("%d%d", &obj[i].w,&obj[i].v);
    
}