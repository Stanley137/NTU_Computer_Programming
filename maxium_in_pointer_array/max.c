#include "max.h"
#include <limits.h>
int max(int *iptr[], int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(*iptr[i]>max)
            max = *iptr[i];
    }
    return max;
}