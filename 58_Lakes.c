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
int find_lakes(int row,int col,int N,int M,int lakes[450][450]){ 
    int right,left,up,down;
    if(!in_lake(row,col,N,M)) //// fuck 
        return 0;
    if(lakes[row][col]==0)
        return 0;
    lakes[row][col] = 0; // lakes[row][col] = 1
    //printf("row: %d, col: %d\n",row,col);
    // if(in_lake(row+1,col,N,M))
    down = find_lakes(row-1,col,N,M,lakes);
    //else if(in_lake(row-1,col,N,M))
    up = find_lakes(row+1,col,N,M,lakes);
    //else if(in_lake(row,col+1,N,M))
    right = find_lakes(row,col+1,N,M,lakes);
    //else if(in_lake(row,col-1,N,M))
    left = find_lakes(row,col-1,N,M,lakes);
    return 1 + (right + left + up + down);
}
int arr[80005];
int main(){
    int lakes[450][450];
    int idx=0;
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
            int num = find_lakes(i,j,N,M,lakes);
            // if(num==1)
            //     continue;
            //printf("%d\n",num);     
            arr[idx] = num;
            idx++;
        }
    }
    qsort(arr,idx,sizeof(int),cmp);
    for(int i=idx-1;i>=0 && arr[i]!=0;i--){
        printf("%d\n",arr[i]);
    }
    return 0;
}   