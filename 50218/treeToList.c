#include <stdio.h>
#include <stdlib.h>
#include "treeToList.h"
List concat_list(List list_1,List list_2){
    if(list_1.head == NULL)
        return list_2;
    else if (list_2.head == NULL)
        return list_1;
    List ret;
    ret.head = list_1.head;
    list_1.tail->left = list_2.head;
    ret.tail = list_2.tail;
    return ret;
}
List node2list(TreeNode * root){
    List ret;
    root->right = NULL;
    ret.head = root;
    ret.tail = root;
    return ret;
}

List treeToListFunc(TreeNode * root){ 
    List ret;
    if(root == NULL){
        ret.head = ret.tail = NULL;
        return ret;
    }
    List left = treeToListFunc(root->left);
    List right = treeToListFunc(root->right);
    if(root->value % 2 == 0)
        return concat_list(node2list(root), concat_list(left, right));
    else
        return concat_list(node2list(root), concat_list(right, left));
}