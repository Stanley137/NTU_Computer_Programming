#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int cmp(const void * a,const void * b){ 
    return (*(int*)a - *(int*)b);
}
bool in_lake(int row,int col,int N,int M){
    if(row>=0 && col>=0 && row<=N-1 && col<=M-1) // in the lake
        return true;
    return false;
}
int find_lakes(int row,int col,int sum,int N,int M,int lakes[450][450]){ // before this recursion's sum
    int right = 0,left = 0 ,up = 0,down = 0;
    if(!(in_lake(row,col,N,M)))
        return 0;
    if(lakes[row][col]==0)
        return sum;
    lakes[row][col] = 0; // lakes[row][col] = 1
    printf("sum: %d, row: %d, col: %d\n",sum,row,col);
    return sum + find_lakes(row+1,col,sum+1,N,M,lakes) + 
            find_lakes(row-1,col,sum+1,N,M,lakes) + find_lakes(row,col+1,sum+1,N,M,lakes); + 
            find_lakes(row,col-1,sum+1,N,M,lakes);
}
int main(){
    int lakes[450][450];
    int arr[16001],idx=0;
    int N,M;
    scanf("%d%d", &N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            scanf("%d",&lakes[i][j]);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(lakes[i][j] == 0)
                continue;
            int num = find_lakes(i,j,0,N,M,lakes);
            arr[idx] = num;
            idx++;
        }
    }
    qsort(arr,idx,sizeof(int),cmp);
    for(int i=idx-1;i>=0;i--)
        printf("%d\n",arr[i]);
    return 0;
}