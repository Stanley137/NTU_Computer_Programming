#include <stdlib.h>
#include <stdio.h>
#include "construct.h"
//#define MAXLENGTH 10
int cmp(const void *a_1,const void *b_1){
    const int *a = a_1, *b = b_1;
    if(*a > *b)
        return -1;
    else if(*a == *b)
        return 0;
    else
        return 1;
}
void copy(int arr1[],int arr2[],int start,int end){
    int index=0;
    for(int i=start;i<=end;i++)
        arr1[index++] = arr2[i];
}
void dump_arr(int arr[],int N){
    for(int i=0;i<N;i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int find_kth(int seq[],int start,int end){
    int to_copy[16384];
    int len = (end - start +1);
    copy(to_copy, seq,start,end);
    //printf("%d\n", len);
    // dump_arr(seq, len);
    // dump_arr(to_copy,len);
    qsort(to_copy, len, sizeof(int), cmp);
    int find_num = to_copy[MAXLENGTH-1];
    for(int i=start;i<=end;i++){
        if(seq[i] == find_num)
            return i;
    }
}
Node* genNode(int value,Node *left,Node *right){
    Node *root = (Node *)malloc(sizeof(Node));
    root->value = value;
    root->left = left;
    root->right = right;
    return root;
}
Node* genList(int seq[],int start,int end){
    if(end < start)
        return NULL;
    return genNode(seq[end], genList(seq,start,end-1), NULL);
}

Node* genTree(int seq[],int start,int end){
    int index = find_kth(seq, start, end);
    //printf("index: %d, %d\n",index, seq[index]);
    if(end - start +1 < MAXLENGTH)
        return genList(seq,start,end);
    return genNode(seq[index], genTree(seq,start,index-1), genTree(seq,index+1, end));
}


Node* ConstructTree(int sequence[], int N){
    return (genTree(sequence,0,N-1));
}