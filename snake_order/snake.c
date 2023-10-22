#include <stdio.h>
void snake(const int *ptr_array[100][100], int m){
    const int *temp_array[10000];
    const int *temp;
    int t_index = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            temp_array[t_index] = ptr_array[i][j];
            t_index++;
        }
    }
    for(int i=0;i<m*m;i++){
        for(int j=0;j<m*m-1;j++){
            if(*temp_array[j] > *temp_array[j+1]){
                temp = temp_array[j];
                temp_array[j] = temp_array[j+1];
                temp_array[j+1] = temp; 
            }
        }
    }
    int rev = 0;
    t_index=0;
    for(int i=0;i<m;i++){
        if(!rev){
            for(int j=0;j<m;j++){
                ptr_array[i][j] = temp_array[t_index];
                t_index++;
            }
            rev = 1;
        }
        else{
            for(int j=m-1;j>=0;j--){
                ptr_array[i][j] = temp_array[t_index];
                t_index++;
            }
            rev = 0;
        }
    }
}
