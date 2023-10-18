#include <stdio.h>
#include <limits.h>
void loops(int N, int *A, int *B[], int ans[4]){
    // find loops
    int length = 1, max_length = INT_MIN, min_length = INT_MAX;
    int value = 1, next_value,max_value = INT_MIN, min_value = INT_MAX; 
    int max, min;
    for(int i=0;i<N;i++){
        int index = i;
        int start_value = *B[index];
        length = 1;
        while(*B[index] != start_value){
            value = start_value;
            index = B[index] - A;
            next_value = *B[index];
            if(next_value == start_value)
                break;
            max = (next_value >= value)? next_value: value;
            min = (next_value <= value)? next_value: value;
            length++;
            if(length >= max_length){
                max_length = length;
                max_value = max;
            }
            if(length <= min_length){
                min_length = length;
                min_value = min;
            }
        }
        if(length == 1){
            min_length = 1;
            min_value = start_value;
        }
    }
}