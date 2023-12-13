#include <stdio.h>
#include <stdlib.h>
#include "construct.h"
int find_balance(int T[],int N){
    if(N<3)
        return -1;
    for(int i=0;i<N;i++){
        int sum = 0;
        for(int j=0;j<i;j++)
            sum += ((j-i) * T[j]);
        for(int j=i+1;j<N;j++)
            sum += ((j-i) * T[j]);
        if(sum == 0)
            return i;
    }
    return -1;
}
Node *genNode(int value,Node *left, Node *right){
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

Node *ConstructTree(int T[], int N){
    int b_points = find_balance(T, N);
    if(N==0)
        return NULL;
    if(b_points != -1){
        int right_len = N - (b_points+1);
        int left_len = N - right_len - 1;
        int *ptr = T;
        printf("value: %d\n", T[b_points]);
        printf("left_len: %d, right_len: %d\n", left_len, right_len);
        if(left_len > 0)
            return genNode(T[b_points], ConstructTree(T,left_len), ConstructTree(ptr+b_points,right_len));
        else
            return genNode(T[b_points], ConstructTree(T,right_len), NULL);
    }
    return genNode(T[b_points], ConstructTree(T,N-1), NULL);
}