#include <stdio.h>
int lotion_compose(int D, int a, int b,int c,int A, int B,int C, long long sum){
    //printf("%d\n", sum);
    if(sum > D)
        return 0;
    if(a<0 || b<0 || c<0)
        return 0;
    if(sum == D)
        return 1;
    if(a>=0 && b>=0 && c>=0){
        if(lotion_compose(D,a-1,b,c,A,B,C,sum+A))
            return 1;
        if(lotion_compose(D,a,b-1,c,A,B,C,sum+B))
            return 1;
        if(lotion_compose(D,a,b,c-1,A,B,C,sum+C))
            return 1;
    }
    return 0;
}
int main(){
    int N, a,b,c,D,A,B,C;
    scanf("%d", &N);
    for(int n=0;n<N;n++){
        scanf("%d%d%d%d%d%d%d", &D, &a,&b,&c,&A,&B,&C);
        int check = lotion_compose(D, a,b,c, A, B,C ,0);
        if(check)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}