#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int check_index(int ori_len,int check_ind){
    if(check_ind<0 || check_ind>=ori_len)
        return 0;
    return 1;
}
void chasing(int **A[], int a, int *B[], int b, int C[], int c){
    for(int i=0;i<a;i++)
        A[i] = NULL;
    for(int i=0;i<b;i++)
        B[i] = NULL;
    char s1[64], d1[64], s2[64], d2[64];
    while(scanf("%s%s%s%s",s1,d1,s2,d2) != EOF){
        int index1 = atoi(d1);
        int index2 = atoi(d2);
        if(strcmp(s1,"A") == 0 && strcmp(s2,"B") == 0  && check_index(a,index1) && check_index(b,index2)){
            
            if(A[index1] == NULL){
                A[index1] = &B[index2];
                printf("1\n");
                continue;
            }
        }
        else if(strcmp(s1,"B") == 0 && strcmp(s2,"C") == 0  && check_index(b,index1) && check_index(c, index2)){
            
            if(B[index1] == NULL){
                B[index1] = &C[index2];
                printf("1\n");
                continue;
            }
        }
        printf("0\n");
    }
}