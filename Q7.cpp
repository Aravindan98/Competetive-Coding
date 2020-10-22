#include<iostream>

using namespace std;

typedef struct node
{
  int value;
  node* left;
  node* right;
}node;

node* create_node(int val)
{
node* new_node =(node*) malloc(sizeof(node));
new_node->value = val;
new_node->left = new_node->right = NULL;
};

class BST
{
public:
  node* BST_root;
  BST(){BST_root=NULL; return;};
  void BST_INSERT_NODE(node* &root,int val);
  void inorder(node* root);
  void computeDistance(node* root,int* i,int a,int b);
  void goDeep(node* root,int* distance,int a);
};

void BST::BST_INSERT_NODE(node* &root,int val)
{
  if(root==NULL)
  {
    root=create_node(val);
    return;
  }
  if(root->value>=val) BST_INSERT_NODE(root->left,val);
  else BST_INSERT_NODE(root->right,val);
};

void BST::inorder(node * root)
{
  if(!root) return;
  inorder(root->left);
  cout<<root->value<<" ";
  inorder(root->right);
};

void BST::goDeep(node* root,int* distance,int a)
{
  if(root->value == a) return;
  (*distance)++;
  if(a<root->value) goDeep(root->left,distance,a);
  else goDeep(root->right,distance,a);
};

void BST::computeDistance(node* root,int* distance,int a, int b)
{
  int value=root->value;
  if(a<value && b<value)
  {
    computeDistance(root->left,distance,a,b);
  }
  if(a>value && b>value)
  {
  computeDistance(root->right,distance,a,b);
  }

  if(a==value)
  {
    goDeep(root,distance,b);
    return;
  }
  else if(b==value)
  {
    goDeep(root,distance,a);
    return;
  }
  else//if(a<value && b>value || a>value && b<value)
  {
    goDeep(root,distance,b);
    goDeep(root,distance,a);
    return;
  }
};

int main()
{
  BST b;
  b.BST_INSERT_NODE(b.BST_root,12);
  b.BST_INSERT_NODE(b.BST_root,1);
  b.BST_INSERT_NODE(b.BST_root,13);
  b.BST_INSERT_NODE(b.BST_root,4);
  b.BST_INSERT_NODE(b.BST_root,23);

  b.inorder(b.BST_root);
  cout<<endl;

  int distance=0;
  int a=1;
  int c=23;

  b.computeDistance(b.BST_root,&distance,a,c);

  cout<<"The distance between "<<a<<" and "<<c<<" is :"<<distance<<endl;
  return 0;
}
