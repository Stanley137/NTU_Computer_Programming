#include <stdio.h>
# define ROW 3
# define COL 5
int array_value(int *arr, int i, int j){
    int num = *(arr + i*COL + j); 
    return num;
}
void set_array_value(int *arr, int i, int j, int value){
    *(arr + i*COL + j) = value;
}
void multiplyMatrix(void ** arrayA, void ** arrayB, void ** arrayC){
    for(int n=0;arrayA[n]!=NULL;n++){
        int *pointerC = arrayC[n];
        for(int i=0;i<ROW;i++){
            int sum = 0;
            for(int coly = 0;coly < ROW;coly++){
                for(int j=0;j<COL;j++){
                int a = array_value(arrayA[n], i, j); // A[i][j]
                int b = array_value(arrayB[n],j,coly); // B[j][i]
                sum += a * b;
                set_array_value(pointerC,i, coly, sum);
            }
            }
        }
    }
}