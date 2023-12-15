#include <stdio.h>
#include "BuildTree.h"
Node* link_node(Node* root,Node* left,Node* right){
    root->left = left;
    root->right = right;
    return root;
}

Node* BuildTree(Node* list1, Node* list2){
    if(list1==NULL && list2==NULL)
        return NULL;
    
    if(list1->val < list2->val){
        Node *root = list1;
        
    }

}