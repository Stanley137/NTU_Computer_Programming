#include <stdio.h> 

void merge(int A[], int B[], int* a[], int* b[]){
    int A_index = 0;
    int B_index = 0;
    int next_index;
    // int a_len = *(&a+1) - a;
    // int b_len = *(&b+1) - b;
    int now_A, a_full = 0, b_full = 0;
    // debugging with NULL
    while((b_full && a[B_index] == NULL) || (a_full && b[B_index] == NULL)){
        printf("A_index: %d, B_index: %d\n",A_index,B_index);
        printf("%d %d\n", a_full, b_full);
        if((A[A_index] < B[B_index]) && !a_full){
            next_index = A_index+1;
            // a is full
            if(a[A_index] == NULL){
                a_full = 1;
                a[A_index] = &B[B_index];
                continue;
            }
            // check for next index 
            if(A[next_index] < B[B_index]){ // next_A < B
                A_index++;
            }
            else{ // next_A > B
                a[A_index] = &B[B_index];
                B_index++;
            }
        }
        else if((A[A_index] > B[B_index]) && !b_full){ // A[A_index] > B[B_index]
            // b is full
            next_index = B_index+1;
            if(b[B_index] == NULL){
                b_full = 1;
                b[B_index] = &A[A_index];
                continue;
            }
            // check for next index
            if(B[next_index] < A[A_index])
                B_index++;
            else{
                b[B_index] = &A[A_index];
                A_index++;
            }
        }
    }
}