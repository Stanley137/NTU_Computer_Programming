#include <stdio.h> 
#include <stdbool.h>
void merge(int A[], int B[], int* a[], int* b[]){
    int A_index = 0, a_index = 0;
    int B_index = 0, b_index = 0;
    // int a_len = *(&a+1) - a;
    // int b_len = *(&b+1) - b;
    bool now_A, a_full = 0, b_full = 0;
    int *now_point;
    // debugging with NULL
    while(!(a[a_index-1] == NULL && b[b_index-1] == NULL)){
        // printf("A_index: %d, B_index: %d\n",A_index,B_index);
        // printf("a_index: %d, b_index: %d\n", a_index,b_index);
        if(A[A_index] < B[B_index]){
            A_index++;
            // a is full
            if(a[a_index] == NULL)
                a_full = 1;
            // check for next index 
            if(A[A_index] < B[B_index]){ // next_A < B
                a_index++;
            }
            else{ // next_A > B
                a[a_index] = &B[B_index];
                a_index++;
            }
        }
        else{ // A[A_index] > B[B_index]
            B_index++;
            // b is full
            if(b[b_index] == NULL)
                b_full = 1;
            // check for next index
            if(B[B_index] < A[A_index])
                b_index++;
            else{
                b[b_index] = &A[A_index];
                b_index++;
            }
        }
    }
}