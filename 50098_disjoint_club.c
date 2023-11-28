#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
void print_bit(bool clubs_to_print[],int N){
    for(int i=0;i<N;i++){
        if(clubs_to_print[i])
            printf("%d\n", i);
    }
}

bool find_disjoint(uint64_t clubs[],uint64_t choose_club,bool clubs_to_print[],int i,int k,int N,int K){
    if(k==K){
        print_bit(clubs_to_print, N);
        return 1;
    }
    if(i>=N)
        return 0;
    if((choose_club & clubs[i])==0){
        uint64_t parse_choose = (choose_club|clubs[i]);
        clubs_to_print[i] = 1;
        //printf("id: %d,choose: %llu\n", i,parse_choose);
        if(find_disjoint(clubs,parse_choose,clubs_to_print,i+1,k+1,N,K))
            return 1;
    }
    clubs_to_print[i] = 0;
    return find_disjoint(clubs,choose_club,clubs_to_print,i+1,k,N,K);
}

int main(){
    int M,N,K,id;
    uint64_t clubs[105] = {0}, choose_club;
    bool clubs_to_print[105] = {0};
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%d", &M);
        clubs[i] = 0;
        for(int j=0;j<M;j++){
            scanf("%d", &id);
            clubs[i] |= ((uint64_t)1<<id);
        }
        //printf("%llu\n", clubs[i]);
    }
    find_disjoint(clubs,0,clubs_to_print,0,0,N,K);
    return 0;
}