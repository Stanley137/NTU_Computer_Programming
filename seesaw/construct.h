#ifndef CONSTRUCT
#define CONSTRUCT
struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};
typedef struct Node Node;
 
Node *ConstructTree(int T[], int N);
#endif