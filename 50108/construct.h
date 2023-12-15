
struct node{
    int value;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

Node* ConstructTree(int sequence[], int N);
