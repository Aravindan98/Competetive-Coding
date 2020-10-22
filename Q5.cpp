#include<iostream>
using namespace std;

typedef struct node
{
  int value;
  node* left;
  node* right;
}node;

class BST
{
public:
  int count;
  node* BST_root;
  BST(){BST_root=NULL; count=0;};
  void BST_INSERT_NODE(node* &BST_root,int value);
  void inorderTraversal(node* BST_root);
  void countSubTreesInRange(node* root,int min,int max);
};

node* createNode(int val)
{
  node* new_node=(node*) malloc(sizeof(node));
  new_node->value=val;
  new_node->left=new_node->right=NULL;
  return new_node;
};

void BST::BST_INSERT_NODE(node* &root, int val)
{
  if(root==NULL)
    {
      root=createNode(val);
      return;
    }

  if(root->value>=val)//left else right
  {
    BST_INSERT_NODE(root->left,val);
  }
  else
  {
    BST_INSERT_NODE(root->right,val);
  }
};

int SubTreeMax(node* root)
{
  while(root->right) root=root->right;
  return root->value;
};

int SubTreeMin(node* root)
{
  while(root->left) root=root->left;
  return root->value;
};

bool checkSubTreeWithinRange(node* root, int min, int max)
{
  if ((SubTreeMax(root)<=max) && (SubTreeMin(root)>=min))
    return true;
  return false;
};

void BST::countSubTreesInRange(node* root,int min,int max)
{
  if(root==NULL)
  {
    return;
  }
  if(checkSubTreeWithinRange(root,min,max))
  {
    count++;
    cout<<root->value<<"  "<<count<<endl;
  }
  countSubTreesInRange(root->left,min,max);
  countSubTreesInRange(root->right,min,max);
  return;
}

void BST::inorderTraversal(node* root)
{
  if(root==NULL)
    return;
  inorderTraversal(root->left);
  cout<<root->value<<" ";
  inorderTraversal(root->right);
  return;
};

int main()
{
  BST b;
  b.BST_INSERT_NODE(b.BST_root,10);
  cout<<b.BST_root->value<<endl;
  b.BST_INSERT_NODE(b.BST_root,12);
  cout<<b.BST_root->value<<endl;
  b.BST_INSERT_NODE(b.BST_root,1);
  cout<<b.BST_root->value<<endl;
  b.BST_INSERT_NODE(b.BST_root,2);
  cout<<b.BST_root->value<<endl;
  b.BST_INSERT_NODE(b.BST_root,5);
/*
  b.BST_INSERT_NODE(b.BST_root,3);
  b.BST_INSERT_NODE(b.BST_root,23);
  b.BST_INSERT_NODE(b.BST_root,42);
*/
  cout<<"INORDER:"<<endl;
  b.inorderTraversal(b.BST_root);
  cout<<endl<<"BST ready!"<<endl;
  b.countSubTreesInRange(b.BST_root,1,6);
  cout<<"count="<<b.count<<endl;
  return 0;
}
