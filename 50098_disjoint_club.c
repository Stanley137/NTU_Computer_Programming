#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
void print_bit(bool chooses[],int N){
    for(int i=0;i<N;i++){
        if(chooses[i])
            printf("%d\n", i);
    }
}
bool find_disjoint(uint64_t clubs[],uint64_t choose_club,bool chooses[],int k,int N,int K){
    if(k==K){
        uint64_t choose = choose_club;
        print_bit(chooses, N);
        for(int i=0;i<N;i++){
            if(chooses[i]){
                choose -= clubs[i];
            }
        }
        if(choose == 0)
            return 1;
        else 
            return 0;
    }
    uint64_t choose;
    for(int i=0;i<N;i++){
        if(chooses[i])
            continue;
        chooses[i] = 1;
        choose = choose_club;
        choose |= clubs[i];
        //printf("i: %d\nchoose:\n", i);
        //print_bit(chooses, N);
        if(find_disjoint(clubs,choose,chooses,k+1,N,K))
            return 1;
        chooses[i] = 0;
        choose_club = choose;
    }
}


int main(){
    int M,N,K,id;
    uint64_t clubs[105] = {0};
    bool chooses[105] = {0};
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%d", &M);
        for(int j=0;j<M;j++){
            scanf("%d", &id);
            clubs[i] |= (1<<id);
        }
        //printf("%llu\n", clubs[i]);
    }
    find_disjoint(clubs,0,chooses,0,N,K);
    print_bit(chooses, N);
    return 0;
}