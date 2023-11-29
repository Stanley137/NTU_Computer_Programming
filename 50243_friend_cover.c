#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
struct Choose
{
    int choose_num;
    uint64_t choose;
};
typedef struct Choose Choose;
void print_bits(uint64_t bits){
    uint64_t bits_c = bits;
    for(int i=0;i<64;i++){
        if((bits_c >> 63))
            printf("1");
        else
            printf("0");
        bits_c = bits_c << 1;
    }
    printf("\n");
}
bool has_covered(uint64_t friend_cover[],Choose selection,int N){
    for(int i=0;i<N;i++){
        if(selection.choose & ((uint64_t)1<<i)) // itself in the relation
            continue;
        if(friend_cover[i] & ~(selection.choose)) // its friend has covered it
            return false;
    }
    return true;
}
int min(int a,int b){
    return (a<b)?a:b;
}


Choose find_selection(uint64_t friend_cover[],uint64_t relation,Choose selection,int index,int N){
    if(has_covered(friend_cover,selection,N)) // 這裡處理了 朋友有關係的情形
        return selection;
    Choose no_ans = {INT_MAX,0};
    if(index==N)
        return no_ans;  

    if((relation & ((uint64_t)1<<index))==0) // 孤兒 
        return find_selection(friend_cover,relation,selection,index+1,N);

    //printf("index:%d, choose_num: %d,selection:\n",index,selection.choose_num);
    //print_bits(selection.choose);
    Choose add = {selection.choose_num+1,selection.choose | ((uint64_t)1<<index)};
    Choose chose_this = find_selection(friend_cover,relation,add,index+1,N);
    Choose dont_chose = find_selection(friend_cover,relation,selection,index+1,N);
    return (dont_chose.choose_num<chose_this.choose_num)? dont_chose: chose_this;
    // if chose_this >= dont_choose(等於的話就取chose_this)保證字典續在前面(細節)
}
int main(){
    int N,M;
    scanf("%d%d", &N,&M);
    uint64_t friend_cover[100] = {0}, relation = 0;
    bool choose[105] = {0};
    int id1,id2;
    for(int i=0;i<M;i++){
        scanf("%d%d",&id1,&id2);
        friend_cover[id1] |= ((uint64_t)1<<id2);
        friend_cover[id2] |= ((uint64_t)1<<id1);
        relation |= (friend_cover[id1] | friend_cover[id2]);
    }
    //print_bits(relation);
    Choose selection = {0,0};
    Choose ret = find_selection(friend_cover,relation,selection,0,N);
    //printf("%d\n", ret.choose_num);
    uint64_t ans = ret.choose;
    //print_bits(ans);
    for(int i=0;i<N;i++){
        if(ans & ((uint64_t)1<<i))
            printf("%d\n",i);
    }
    // for(int i=0;i<N;i++)
    //     printf("%llu\n", friend_cover[i]);
    return 0;
}