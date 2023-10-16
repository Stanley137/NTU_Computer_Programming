#include <stdio.h>
#include <stdlib.h>
#include "count.h"

typedef struct s_pair{
    int* address;
    int count;
} s_pair;

int cmp(const void* a, const void* b){
    s_pair* pa = (s_pair*)a;
    s_pair* pb = (s_pair*)b;

    int na = *(pa->address);
    int nb = *(pb->address);
    // printf("cmping %d %d\n", na, nb);

    if(pa->count != pb->count) return pa->count - pb->count;
    else return (na) - (nb);
}

void count(int **p[]){
    s_pair pair[512] = {0};
    int cnt = 0;

    for(int i = 0; p[i] != NULL; i++){
        int* a = *(p[i]);

        int j;
        for(j = 0; j < cnt; j++){
            if(pair[j].address == a){
                pair[j].count++;
                break;
            }
        }
        if(j == cnt){
            pair[cnt].address = a;
            pair[cnt].count = 1;
            cnt++;
        }
    }
    qsort(pair, cnt, sizeof(s_pair), cmp);

    for(int i = 0; i < cnt; i++){
        printf("%d %d\n", *(pair[i].address), pair[i].count);
    }
}
