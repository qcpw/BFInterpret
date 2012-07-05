typedef struct node node;
typedef struct ternaryTree ternaryTree;


struct ternaryTree{
  struct node{
    node *right, *left, *center;
    int data;
  };
  node* root;
};

void initNode(node* N, int data){
  N = (node*) malloc(sizeof(node));
  N
}

void initTernaryTree(ternaryTree* T){
  initNode(T->root);

}
