#include <stdio.h> 
#include <stdbool.h>
void merge(int A[], int B[], int* a[], int* b[]){
    int A_index = 0;
    int B_index = 0;
    int **last = NULL; // This technique is important
    bool last_in_a;
    do{
        if(A[A_index] < B[B_index]){
            if(last == NULL)
                last = &a[A_index];
            else{
                *last = &A[A_index];
                last = &a[A_index];
            }
            A_index++;
            last_in_a = true;
        }
        else{
            if(last == NULL)
                last = &b[B_index];
            else{
                *last = &B[B_index];
                last = &b[B_index];
            }
            B_index++;
            last_in_a = false;
        }
    }while(*last != NULL);
    *last = (last_in_a)? &B[B_index]: &A[A_index];

}