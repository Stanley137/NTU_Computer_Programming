struct Node
{
          int val;
          struct Node *left, *right;
};
typedef struct Node Node;

Node* BuildTree(Node* list1, Node* list2);