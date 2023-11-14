#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define C 10000
#define LEN 101
char hash_table[1000][C][LEN] = {"\0"};
int calc_key(char str[], int S){
    int len = strlen(str);
    int sum = 0;
    for(int i=0;i<len;i++){
        if(isdigit(str[i]))
            sum += (str[i] - '0');
        else
            sum += str[i];
    }
    return sum % S;
}
void insert(char hash_table[1000][C][LEN], int key, char str[]){
    for(int i=0;i<C;i++){
        if(strcmp(hash_table[key][i], "\0")==0){
            strcpy(hash_table[key][i], str);
            // printf("Insert: %s, colli: %d\n", hash_table[key][i], i);
            break;
        }
    }
}
int find_table(char hash_table[1000][C][LEN], int key, char str[]){
    for(int i=0;i<C;i++){
        if(strcmp(hash_table[key][i], str) == 0)
            return key;
        else if(strcmp(hash_table[key][i], "\0") == 0)
            break;
    }
    return -1;
}
int main(){
    int S, N, Q;
    scanf("%d%d%d", &S, &N, &Q);
    char str[LEN];
    for(int i=0;i<N;i++){ // insert
        scanf("%s", str);
        int key = calc_key(str, S);
        //printf("Key: %d\n", key);
        insert(hash_table,key,str);
    }
    for(int i=0;i<Q;i++){
        scanf("%s", str); // find
        int key = calc_key(str, S);
        int result = find_table(hash_table, key, str);
        printf("%d\n", result);
    }
    return 0;
}