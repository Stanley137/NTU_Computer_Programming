#include <stdio.h>
//#define DEBUG
#define table_len 100000
#define colli 10
int hash(int k,int S){
    int hash = (k * 77 + 2222); 
    return  hash % S; 
}
int main(){
    int S, C;
    int hash_table[table_len][colli];
    // init
    for(int i=0;i<table_len;i++){
        for(int j=0;j<colli;j++)
            hash_table[i][j] = -1;
    }
    int num;
    scanf("%d%d", &S,&C);
    while(scanf("%d", &num) != EOF){
        int index = hash(num, S);
        int flag = 1;
        #ifdef DEBUG
        printf("dump: %d %d\n", num, index);
        #endif
        // inserted or removed
        for(int i=0;i<C;i++){
            //printf("content: %d\n", hash_table[index][i]);
            if(hash_table[index][i] == num){ // removed
                hash_table[index][i] = -1;
                printf("%d %d\n", num, index);
                flag = 0;
                break;
            }
        }
        if(flag){
            for(int i=0;i<C;i++){
                if(hash_table[index][i] == -1){ // inserted
                    hash_table[index][i] = num;
                    break;;
                }
            }
        }
    }
    return 0;
}