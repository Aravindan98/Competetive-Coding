#include<iostream>

using namespace std;

class node
{
public:
  int value;
  node* right;
  node* left;
};

node* create_node(int key)
{
  node* new_node = new node();
  new_node->value = key;
  new_node->left = new_node->right = NULL;
  return new_node;
};

void toBST(node* &root, int* arr, int start, int end, int size)
{
    if(start>end)
    {
      root=NULL;
      return;
    }
    root=create_node(arr[start]);
    int partition=start+1;
    while(partition<size && arr[start]>=arr[partition])
    {
      partition++;
    }
    if(partition>start+1)
      toBST(root->left, arr, start+1, partition-1, size);

    if(partition<=end)
      toBST(root->right, arr, partition, end, size);
    return;
};

void inorder(node* root)
{
  if(root==NULL)
  {
    return;
  }
  inorder(root->left);
  cout<<root->value<<" ";
  inorder(root->right);
};

void preorder(node* root)
{
  if(root==NULL)
    return;
  cout<<root->value<<" ";
  preorder(root->left);
  preorder(root->right);
}

int main()
{
  node* BST;
  int arr[6]={10,5,1,7,40,50};
  int size=sizeof(arr)/sizeof(arr[0]);
  toBST(BST, arr, 0, size-1, size);
  cout<<"preorder"<<endl;
  preorder(BST);
  cout<<endl<<"inorder"<<endl;
  inorder(BST);
  cout<<endl;
  return 0;
}
