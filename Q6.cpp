#include<iostream>
#include<queue>

using namespace std;

typedef struct node{
int value;
node* left;
node* right;
}node;

node* create_node(int val)
{
   node* new_node=(node*)malloc(sizeof(node));
   new_node->value=val;
   new_node->left = new_node->right = NULL;
   return new_node;
};

class BST
{
public:
  int size;
  node* BST_root;
  int* heap;

  BST(){BST_root=NULL; size=0; heap=NULL;};
  node* getBSTRoot(){return BST_root;};
  void inorder(node* root,int* i);
  void BST_preorder_insert(node* root,int* i);
  void levelOrder(int* i, queue<node*> s);
  void BST_INSERT_NODE(node* &root,int val);
  void BST_TO_HEAP();
  void inorder_print(node* root);
  void printHeap()
  {
    cout<<endl<<"Printing Heap"<<endl;
    for(int i = 0; i<size;  i++)
    {
      cout<<heap[i]<<" ";
    }
  };
  void initializeHeap(){heap=new int[size];};
};

void BST::BST_INSERT_NODE(node* &root,int val)
{
  if(root == NULL)
  {
    root=create_node(val);
    size++;
    return;
  }
  if(root->value>=val) BST_INSERT_NODE(root->left,val);
  else BST_INSERT_NODE(root->right,val);
}

void BST::BST_TO_HEAP()
{
  int i=0;
  inorder(BST_root,&i);
  //heap would be a sorted array
  printHeap();
  //i=0;
  //BST_preorder_insert(BST_root,&i);
  //queue<node*> q;
  //i=0;
  //q.push(BST_root);
  //levelOrder(&i,q);
};

void BST::inorder(node* root,int* i)
{
if(root == NULL)
  return;
inorder(root->left,i);
heap[*i]=root->value;
(*i)++;
inorder(root->right,i);
};

void BST::BST_preorder_insert(node* root, int* i)
{
  if(root == NULL)
    return;
  root->value=heap[*i];
  (*i)++;
  BST_preorder_insert(root->left,i);
  BST_preorder_insert(root->right,i);
};

void BST::levelOrder(int* i, queue<node*> q)
{
  node* root;
  while(!q.empty())
  {
    root=q.front();
    q.pop();
    heap[*i]=root->value;
    (*i)++;
    if(root->right!=NULL)
      q.push(root->right);
    if(root->left!=NULL)
      q.push(root->left);
  }
};

void BST::inorder_print(node* root)
{
  if(root==NULL) return;
  inorder_print(root->left);
  cout<<root->value<<" ";
  inorder_print(root->right);
}

int main()
{
  BST b;
  node* bst_root=b.getBSTRoot();
  b.BST_INSERT_NODE(bst_root,5);
  b.BST_INSERT_NODE(bst_root,7);
  b.BST_INSERT_NODE(bst_root,3);
  b.BST_INSERT_NODE(bst_root,6);
  b.BST_INSERT_NODE(bst_root,9);
  b.BST_INSERT_NODE(bst_root,2);
  b.BST_INSERT_NODE(bst_root,4);
  b.inorder_print(bst_root);
  b.initializeHeap();

  //b.BST_TO_HEAP();
  int i=0;
  int* heap=b.heap;
  b.inorder(bst_root, &i);
  b.printHeap();
  cout<<endl;
  i=0;
  b.BST_preorder_insert(bst_root,&i);
  queue<node*> q;
  i=0;
  q.push(bst_root);
  b.levelOrder(&i,q);
  b.printHeap();
  return 0;
}
