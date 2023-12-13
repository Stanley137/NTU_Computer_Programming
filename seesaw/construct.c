#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "construct.h"
// int find_balance(int T[],int N){
//     for(int i=0;i<N;i++){
//         int sum = 0;
//         for(int j=0;j<i;j++)
//             sum += ((j-i) * T[j]);
//         for(int j=i+1;j<N;j++)
//             sum += ((j-i) * T[j]);
//         if(sum == 0)
//             return i;
//     }
//     return -1;
// }
int find_balance(int T[],int N){
    uint64_t M = 0;
    uint64_t mass_weight = 0;
    if(N<3)
        return -1;
    for(int i=0;i<N;i++){
        M += T[i];
        mass_weight += T[i] * i;
    }
    if(mass_weight % M == 0)
        return mass_weight / M;
    else
        return -1;
}
Node *genNode(int value,Node *left, Node *right){
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}
 Node *genList(int T[],int N){
    if(N==0)
        return NULL;
    return genNode(T[N-1], genList(T,N-1), NULL);
 }


Node *ConstructTree(int T[], int N){
    int b_points = find_balance(T, N);
    if(N==0)
        return NULL;
    if(b_points != -1){
        int right_len = N - (b_points+1);
        int left_len = N - right_len - 1;
        int *ptr = T;
        return genNode(T[b_points], ConstructTree(T,left_len), ConstructTree(ptr+b_points+1,right_len));
    }   
    return genList(T, N);
}