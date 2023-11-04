#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int digits(char digit[]){
    int len = strlen(digit);
    for(int i=0;i<len;i++){
        if(!isdigit(digit[i]))
            return 0;
    }
    return 1;
}
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
    char str_line[64];
    while(fgets(str_line, 64, stdin) != NULL){
        char *first, *second;
        char *dig1, *dig2;
        int num1, num2;
        first = strtok(str_line, " \t\n");
        if(first == NULL){
            printf("0\n");
            continue;
        }
        //debug printf("%s\n", first);
        dig1 = strtok(NULL, " \t\n");
        if(dig1 == NULL){
            printf("0\n");
            continue;
        }
        // printf("digt %s\n", dig1);
        //debug printf("%s\n", dig1);
        if(!digits(dig1)){
            printf("0\n");
            continue;
        }
        else
            num1 = atoi(dig1);
        // printf("num1: %d\n", num1); 
        second = strtok(NULL, " \t\n");
        // printf("second: %s\n", second);
        if(second == NULL){
            printf("0\n");
            continue;
        }
        dig2 = strtok(NULL, " \t\n");
        // printf("%s\n", dig2);
        if(dig2 == NULL){
            printf("0\n");
            continue;
        }
        if(!digits(dig2)){
            printf("0\n");
            continue;
        }
        else
            num2 = atoi(dig2);
        // printf("DEBUG out: %s %s %s %s\n", first, dig1, second, dig2);
        if(strtok(NULL, " \t\n") != NULL){
            printf("0\n");
            continue;
        }
        else{
            // printf("DEBUG: %s %d %s %d\n", first, num1, second, num2);
            if(strcmp(first, "A") == 0 && strcmp(second, "B") == 0 
            && check_index(a, num1) && check_index(b, num2)){
                A[num1] = &B[num2];
                printf("1\n");
                continue;
            }
            else if(strcmp(first, "B") == 0 && strcmp(second, "C") == 0 
            && check_index(b, num1) && check_index(c, num2)){
                B[num1] = &C[num2];
                printf("1\n");
                continue;
            }
        }
        printf("0\n");
    }

}