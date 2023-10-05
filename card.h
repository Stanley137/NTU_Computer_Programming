#include <stdio.h>
#include <math.h>

void shuffle(int *deck[]){
    int len = 0;
    while(deck[len] != NULL){
        len++;   
    }
    int start = 0;
    int half = ceil((len-1)/2) + 1;
    int *ptr[len];
    for(int i=0;i<len;i++){
        if(i%2==0){
            ptr[i] = deck[start];
            start++;
        } 
        else{
            ptr[i] = deck[half];
            half++;
        }
    }
    for(int i=0;i<len;i++)
        deck[i] = ptr[i];
}

void print(int *deck[]){
    int index =0;
    while(deck[index] != NULL){
        printf("%d ",*deck[index]);
        index++;
    }
}