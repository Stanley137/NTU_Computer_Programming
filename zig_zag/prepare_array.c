#include <stdio.h>
void prepare_array(int buffer[], int *array[], int row, int column[]){
    int * pointer_buffer = buffer;
    for(int i=0;i<row;i++){
        array[i] = pointer_buffer;
        pointer_buffer += column[i];
    }
}