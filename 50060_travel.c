#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
void print_bit(uint64_t bits){
    uint64_t bits_print = bits;
    for(int i=0;i<64;i++){
        if(bits_print>>63)
            printf("1");
        else
            printf("0");
        bits_print <<= 1;
    }
}

int min(int a,int b){
    return (a<b)?a:b;
}

int find_path(uint64_t visit,uint64_t visited,int node[20][20],int N,int index,int distance){
    if(visit==visited)
        return distance;
    if(index==N)
        return INT8_MAX;
    int min_distance = INT8_MAX;
    for(int i=0;i<N;i++){
        if((1<<index)&visited)
            continue;
        visited |= (1<<index);
        distance = find_path(visit,visited,node,N,i,distance+node[index][i]);
        min_distance = min(min_distance,distance);
        visited &= ~(1<<index);
    }
    return min_distance;
}


int main(){
    int node[20][20];
    int N;
    uint64_t visit = 0;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &node[i][j]);
        }
        visit |= (1<<i);
    }
    print_bit(visit);
    // // debug
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++)
    //         printf("%d ", node[i][j]);
    //     printf("\n");
    // }
    // //
    return 0;
}