#include <stdio.h>
#define MAXN 10
struct Node
{
    int val;
    struct Node * left;
    struct Node * right;
};
typedef struct Node Node;
int list_len(Node *node){
    int len = 0;
    Node *next = node;
    while(next != NULL){
        len++;
        printf("%d\n", len);
        next = next->left;
    }
    return len;
}
int main(){
    Node l1[MAXN], l2[MAXN];
    int n,num;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
            scanf("%d", &num);
            l1[i].val = num;
            l1[i].left = &l1[i+1];
            l1[i].right = NULL;
    }
    l1[n-1].left = NULL;
    printf("%d\n", list_len(&l1[0]));
    return 0;
}