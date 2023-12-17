#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
void traversal(Node *root, int N, int command[]){
    Node *current[1010];
    current[0] = root; // the index point to the current's parent 
    int layer = 0;
    for(int i=0;i<N;i++){
        int c = command[i];
        //printf("command: %d, current_label: %d\n", c, current->label);
        if(c==0){
            printf("%d\n", current[layer]->label);
            return;
        }
        else if(c==1){
            printf("%d\n", current[layer]->label);
        }
        else if(c==2){
            if(layer-1<0){
                printf("%d\n", current[layer]->label);
                return;
            }
            layer--;
        }
        else if(c==3){
            if(current[layer]->left == NULL){
                printf("%d\n", current[layer]->label);
                return;
            }
            layer++;
            current[layer] = current[layer-1]->left;
        }
        else if(c==4){
            if(current[layer]->right == NULL){
                printf("%d\n", current[layer]->label);
                return;
            }
            layer++;
            current[layer] = current[layer-1]->right;
        }
        else if(c==5){
            // printf("parent_label: %d\n", parent[layer]->label);
            // printf("current_label: %d\n", current->label);
            // printf("parent_left: %p, parent_right: %p\n", parent[layer]->left,parent[layer]->right);
            // printf("current: %p\n", current);
            if(layer<=0 || current[layer-1]->left == NULL || current[layer-1]->right == NULL){
                printf("%d\n", current[layer]->label);
                return;
            }
            if(current[layer-1]->left == current[layer]){
                current[layer] = current[layer-1]->right;
                //printf("here");
                //printf("current: %p\n", current);
            }
            else if(current[layer-1]->right == current[layer])
                current[layer] = current[layer-1]->left;
            // printf("current_label: %d\n", current->label);
        }
    }
    return;
}