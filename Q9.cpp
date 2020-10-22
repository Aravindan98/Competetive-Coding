#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int value;
  node* left;
  node* right;
  int horizontal_dist;
}node;

map<int,vector<int>> m;

node* create_node(int val)
{
  node* new_node=(node*)malloc(sizeof(node));
  new_node->value=val;
  new_node->left=new_node->right=NULL;
  new_node->horizontal_dist=0;
  return new_node;
};

class BST
{
  public:
    node* BST_root;
    BST(){BST_root=NULL;};
    void insert(node*& root,int val,int* h);
    void print_inorder(node* root);
};

void BST::insert(node* &root,int val,int* h)
{
if(root==NULL)
{
  root=create_node(val);
  root->horizontal_dist=*h;
  m[*h].push_back(root->value);
  //cout<<root->value<<","<<root->horizontal_dist<<"   ";
  *h=0;
  return;
}
if(root->value>=val)
{
  (*h)--;
  insert(root->left,val,h);
}
else
{
  (*h)++;
  insert(root->right,val,h);
}
};

void BST::print_inorder(node* root)
{
  if(root==NULL){return;}
  print_inorder(root->left);
  cout<<"("<<root->value<<","<<root->horizontal_dist<<")   ";
  print_inorder(root->right);
  cout<<endl;
  return;
};

int main()
{
  BST b;
  int h=0;
  b.insert(b.BST_root,4,&h);
  b.insert(b.BST_root,2,&h);
  b.insert(b.BST_root,56,&h);
  b.insert(b.BST_root,21,&h);
  b.insert(b.BST_root,1,&h);

  b.print_inorder(b.BST_root);

  map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
  return 0;
}
