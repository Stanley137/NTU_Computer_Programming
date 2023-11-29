    #include <stdio.h>
    #include <stdbool.h>
    #include <limits.h>
    // #include <stdint.h>
    // void print_bit(uint64_t bits){
    //     uint64_t bits_print = bits;
    //     for(int i=0;i<64;i++){
    //         if(bits_print>>63)
    //             printf("1");
    //         else
    //             printf("0");
    //         bits_print <<= 1;
    //     }
    //     printf("\n");
    // }

    int min(int a,int b){
        return (a<b)?a:b;
    }

    int find_path(bool visited[],int steps,int node[20][20],int N,int start,int distance,int *min_p){
        if(steps == N-1){
            //printf("start: %d,next: 0\n",start);
            int cmp_distance = distance + node[start][0];
            if(cmp_distance < *min_p)
                *min_p = cmp_distance;
            return *min_p;
        }
        if(distance >= *min_p)
            return INT_MAX;
        int min_distance = INT_MAX;
        for(int i=1;i<N;i++){
            //print_bit(visited);
            if(!visited[i])  {
            //printf("start: %d,next: %d\n",start,i);
            //printf("now_distance: %d,next_distance: %d\n", distance,distance+node[start][i]);
            visited[i] = 1;
            int distance_new = find_path(visited,steps+1,node,N,i,distance+node[start][i],min_p);
            min_distance = min(min_distance,distance_new);
            visited[i] = 0;
            }
        }
        //printf("min_distance: %d\n",min_distance);
        return min_distance;
    }


    int main(){
        int node[20][20];
        int N;
        int min_v = INT_MAX;
        bool visited[20] = {0};
        visited[0] = 1;
        // uint64_t visit;
        scanf("%d", &N);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d", &node[i][j]);
            }
            //visit |= (1<<i);
        }
        int dis = find_path(visited,0,node,N,0,0,&min_v);
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