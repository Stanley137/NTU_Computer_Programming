#include <stdio.h>
#define N 100
int **first_level[N];
int *second_level[1000000];
int ***constructTable(int A[], int B[]){
    int offset = 0;
    int index = 0;
    int i = 0;
    for(i=0; A[i] != 0;i++){   
        first_level[i] = &second_level[offset];
        for(int j=0;j<=A[i];j++){
            if(j == A[i]){
                second_level[offset+j] = NULL;
                offset += (j+1);
                break;
            }
            second_level[offset+j] = &B[index]; 
            while(B[index] != 0)
                index++;
            index++;
        }
    }
    first_level[i] = NULL;
    int ***first = first_level;
    return first;
}