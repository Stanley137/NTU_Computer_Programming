#include <stdio.h>
#include "BuildTree.h"
Node* link_node(Node* root,Node* left,Node* right){
    root->left = left;
    root->right = right;
    return root;
}
int list_len(Node *node){
    int len = 0;
    Node *next = node;
    while(next != NULL){
        len++;
        //printf("%d\n", len);
        next = next->left;
    }
    return len;
}
Node* ret_head(Node *list){
    int len = list_len(list);
    int half; 
    if(len % 2==0)
        half = len / 2;
    else
        half = (len+1) / 2;
    Node *next = list;
    for(int n=0;n<half;n++){
        if(n==half-1){
            Node *prev = next;
            next = next->left;
            prev->left = NULL;
        }
        else
            next = next->left;
    }
    return next;
}

Node* BuildTree(Node* list1, Node* list2){
    Node *head1 = list1, *head2 = list2, *root;
    if(head1==NULL && head2==NULL)
        return NULL;
    // one of the list is null
    if(head1==NULL){
        root = head2;
        head2 = head2->left;
        link_node(root, BuildTree(NULL, head2), NULL);
    }
    else if(head2==NULL){
        root = head1;
        head1 = head1 -> left;
        link_node(root, BuildTree(head1,NULL), NULL);
    }
    else{
        if(head1->val < head2->val){ // cmp head root is head1
            root = head1;
            head1 = head1->left;
            Node *r_head1 = ret_head(head1);
            Node *r_head2 = ret_head(head2);
            link_node(root, BuildTree(head1, head2), BuildTree(r_head1, r_head2));
        }
        else{
            root = head2;
            head2 = head2->left;
            Node *r_head1 = ret_head(head1);
            Node *r_head2 = ret_head(head2);
            link_node(root, BuildTree(head1, head2), BuildTree(r_head1, r_head2));
        }
    }
    return root;
}