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
    int find_balance(int T[],int start,int end){
        if(end - start<2)
            return -1;
        uint64_t Mass = 0;
        uint64_t m_weight = 0;
        for(int i=start;i<=end;i++){
            Mass += T[i];
            m_weight += (i * T[i]);
        }
        if(m_weight%Mass == 0)
            return m_weight/Mass;
        return -1;
    }
    Node *genNode(int value,Node *left, Node *right){
        Node *node = (Node *)malloc(sizeof(Node));
        node->value = value;
        node->left = left;
        node->right = right;
        return node;
    }
    Node *genList(int T[],int start, int end){
        if(end < start)
            return NULL;
        return genNode(T[end], genList(T,start,end-1), NULL);
    }

    Node *genTree(int T[],int start,int end){
        if(end < start)
            return NULL;
        int balance = find_balance(T, start, end);
        if(balance != -1){
            return genNode(T[balance], genTree(T,start,balance-1), genTree(T,balance+1,end));
        }
        return genList(T,start,end);
    }

    Node *ConstructTree(int T[], int N){
        return genTree(T, 0, N-1);
    }