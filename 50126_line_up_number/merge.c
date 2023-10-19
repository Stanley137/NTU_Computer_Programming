#include <stdio.h> 
#include <stdbool.h>
void merge(int A[], int B[], int* a[], int* b[]){
    int A_index = 0, a_index = 0;
    int B_index = 0, b_index = 0;
    bool now_A;
    int *now_point;
    // debugging with NULL
    while(!(a[a_index] == NULL && b[b_index] == NULL)){
        printf("A_index: %d, B_index: %d\n",A_index,B_index);
        printf("a_index: %d, b_index: %d\n", a_index,b_index);
        if(A[A_index] < B[B_index]){
            A_index++;
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