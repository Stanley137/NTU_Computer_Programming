#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void loops(int N, int *A, int *B[], int ans[4]){
    // find loops
    int length = 1, max_length = INT_MIN, min_length = INT_MAX;
    int value = 1, next_value,max_value = INT_MIN, min_value = INT_MAX; 
    int total_length = N;
    int * dp = (int *)malloc(sizeof(int) * 1000000);
    for(int i=0;i<1000000;i++) dp[i] = 1;

    for(int i=0; i < N;i++){
        if(dp[i] == 0)
            continue;
        int max = INT_MIN, min = INT_MAX;
        int index = i;
        int start_value = *B[index];
        length = 0;
        value = start_value;
        do{
            // printf("index: %d\n", index);
            dp[index] = 0;
            index = B[index] - A;
            next_value = *B[index];
            // printf("value: %d\n", value);
            // printf("next_value: %d\n", next_value);
            max = (value >= max)? value: max;
            min = (value <= min)? value: min;
            value = next_value;
            //printf("max: %d, min: %d\n", max,min);
            length++;
        }while(next_value != start_value);
        // printf("finish loops\n");
        if(length > max_length){
            max_length = length;
            max_value = max;
        }
        else if(length == max_length){
            if(max > max_value)
                max_value = max;
        }
        if(length < min_length){
            min_length = length;
            min_value = min;
        }
        else if(length == min_length){
            if(min < min_value)
                min_value = min;
        }
        // if(length >= max_length){
        //     max_length = length;
        //     if(max > max_value)
        //         max_value = max;
        // }
        // if(length <= min_length){
        //     min_length = length;
        //     if(min < min_value)
        //         min_value = min;
        //     printf("min_value: %d\n", min_value);
        // }
    }
    ans[0] = max_length;
    ans[1] = min_length;
    ans[2] = max_value;
    ans[3] = min_value;
}