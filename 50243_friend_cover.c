#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
void print_bits(uint64_t bits){
    uint64_t bits_c = bits;
    for(int i=0;i<64;i++){
        if((bits_c >> 63) == 1)
            printf("1");
        else
            printf("0");
        bits_c = bits_c << 1;
    }
    printf("\n");
}
int min(int a,int b){
    return (a<b)?a:b;
}

int find_relation(uint64_t friend_cover[],uint64_t relation,bool choose[],int index,int choose_num,int num_people){
    if(relation == 0 || index == num_people)
        return choose_num;
    uint64_t new_relation = relation & ~(friend_cover[index]);
    choose[index] = 1;
    printf("index: %d\n",index);
    printf("relation:\n"); print_bits(relation);
    printf("new_relation:\n"); print_bits(new_relation);
    int pick = find_relation(friend_cover,new_relation,choose,index+1,choose_num+1,num_people);
    int not_pick = find_relation(friend_cover,relation,choose,index+1,choose_num,num_people);
    if(pick > not_pick) // not_pick < pick
        choose[index] = 0;
}


int main(){
    int N,M;
    scanf("%d%d", &N,&M);
    uint64_t friend_cover[100] = {0}, relation = 0;
    bool choose[105] = {0};
    int id1,id2;
    for(int i=0;i<M;i++){
        scanf("%d%d",&id1,&id2);
        relation |= (1<<id1);
        relation |= (1<<id2);
        print_bits(relation);
        friend_cover[id1] |= ((uint64_t)1<<id2);
        friend_cover[id2] |= ((uint64_t)1<<id1);
    }
    find_relation(friend_cover,relation,choose,0,0,N);
    for(int i=0;i<N;i++)
        if(choose[i])
            printf("%d\n", i);
    // for(int i=0;i<N;i++)
    //     printf("%llu\n", friend_cover[i]);
    return 0;
}