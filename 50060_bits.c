#include <stdio.h>
#include <limits.h>
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
    printf("\n");
}
 
int min(int a,int b){
    return (a<b)?a:b;
}
 
int find_path(uint64_t visit,uint64_t visited,int node[20][20],int N,int start,int distance,int *min_p){
    if(visited == visit){
        //printf("start: %d,next: 0\n",start);
        int cmp_distance = distance + node[start][0];
        if(cmp_distance < *min_p)
            *min_p = cmp_distance;
        return *min_p;
    }
    if(distance >= *min_p)
        return INT_MAX;
    int min_distance = INT_MAX;
    uint64_t visited_new = visited;
    for(int i=1;i<N;i++){
        //print_bit(visited);
        if(((uint64_t)1<<i)&visited)  
            continue;
        // printf("start: %d,next: %d\n",start,i);
        // printf("now_distance: %d,next_distance: %d\n", distance,distance+node[start][i]);
        visited_new |= ((uint64_t)1<<i);
        uint64_t distance_new = find_path(visit,visited_new,node,N,i,distance+node[start][i],min_p);
        min_distance = min(min_distance,distance_new);
        visited_new &= ~((uint64_t)1<<i);
    }
    //printf("min_distance: %d\n",min_distance);
    return min_distance;
}
 
 
int main(){
    int node[20][20];
    int N;
    int min_v = INT_MAX;
    uint64_t visit = 0;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &node[i][j]);
        }
        visit |= (1<<i);
    }
    int dis = find_path(visit,(uint64_t)1,node,N,0,0,&min_v);
    printf("%d\n", dis);
    // // debug
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++)
    //         printf("%d ", node[i][j]);
    //     printf("\n");
    // }
    // //
    return 0;
}