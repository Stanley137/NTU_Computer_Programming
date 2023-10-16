#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define N 512
void count(int **p[]){
    int * second_order[N];
    int final_num_count[N] = {0};
    int count_index = 0;
    for(int i=0;p[i] != NULL; i++){
        // check second_order_list
        bool set = true;
        for(int j=0;j<count_index;j++){
            if(*p[i] == second_order[j]){
                final_num_count[j]++;
                set = false;
                break;
            }
        }
        // if not, insert to second_order_list
        if(set){
            second_order[count_index] = *p[i];
            final_num_count[count_index] = 1;
            count_index++;
        }
    }
    // sort reach times
    for(int i=0;i<count_index-1;i++){
        for(int j=0;j<count_index-1;j++){
            if(final_num_count[j] > final_num_count[j+1]){
                int temp = final_num_count[j];
                final_num_count[j] = final_num_count[j+1];
                final_num_count[j+1] = temp;
                int * temp_ptr = second_order[j];
                second_order[j] = second_order[j+1];
                second_order[j+1] = temp_ptr;
            }
        }
    }
    // sort value
    // int times = final_num_count[count_index - 1];
    // printf("%d\n", times);
    for(int i=0;i<count_index-1;i++){
        for(int j=0;j<count_index-1;j++){
            if(*second_order[j] > *second_order[j+1] && (final_num_count[j]==final_num_count[j+1])){
                int *temp_ptr = second_order[j];
                second_order[j] = second_order[j+1];
                second_order[j+1] = temp_ptr;
            }
        }
    }
    // print out
    for(int i=0;i<count_index;i++){
        printf("%d %d\n", *second_order[i], final_num_count[i]);
    }

}