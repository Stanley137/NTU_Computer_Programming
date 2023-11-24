#include <stdio.h>
#include <stdint.h>
int find_disjoint(uint64_t clubs,int i,int N,int K){
    
}

int main(){
    int N,K,id;
    uint64_t clubs[105] = {0};
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++){
        while(scanf("%d", &id) != EOF){
            clubs[i] += (1<<id);
        }
    }
    
}