#include <stdio.h>
# define ROW 3
# define COL 5
int array_value(int *arr, int i, int j, int col){
    int num = *(arr + i*col + j); 
    return num;
}
void set_array_value(int *arr, int i, int j, int value, int col){
    *(arr + i*col + j) = value;
}
void multiplyMatrix(void ** arrayA, void ** arrayB, void ** arrayC){
    for(int n=0;arrayA[n]!=NULL;n++){
        int *pointerC = arrayC[n];
        //printf("n:%d\n", n);
        for(int i=0;i<ROW;i++){
            for(int coly = 0;coly < ROW;coly++){
                int sum = 0;
                for(int j=0;j<COL;j++){
                    int a = array_value(arrayA[n], i, j, COL); // A[i][j]
                    int b = array_value(arrayB[n],j,coly,ROW); // B[j][i]
                    sum += a * b;
                    //printf("a:%d,b:%d,sum:%d\n", a,b ,sum);
                    set_array_value(pointerC,i, coly, sum, ROW);
            }
            }
        }
    }
}