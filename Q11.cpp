#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
  int value;
  Node* left;
  Node* right;
  int height;
};

Node* newNode(int val)
{
  Node* node=new Node();
  node->value=val;
  node->left=node->right=NULL;
  node->height=1;
  return node;
};

int max(int a,int b){ return(a>b?a:b);}

int height(Node* node)
{
  if(node==NULL) return 0;
  else return node->height;
}

int getBalance(Node* node)
{
  return height(node->right)-height(node->left);
};

Node* leftRotate(Node* parent)
{
Node* child=parent->right;
Node* sub=child->left;

child->left=parent;
parent->right=sub;
// adjust the heights of the parent and child
child->height=1+(max(height(child->left),height(child->right)));
parent->height=1+(max(height(parent->left),height(parent->right)));

return child;
};

Node* rightRotate(Node* parent)
{
Node* child=parent->left;
Node* sub=child->right;

child->right=parent;
parent->left=sub;
// adjust the heights of the parent and child
child->height=1+(max(height(child->left),height(child->right)));
parent->height=1+(max(height(parent->left),height(parent->right)));

return child;
};

Node* insert(Node* root, int val)
{
if(root==NULL)
{
  return newNode(val);
}

if(root->value>val) root->left=insert(root->left,val);
else root->right=insert(root->right,val);

root->height=1+max(height(root->left),height(root->right));

int balance=getBalance(root);

if(balance<-1 && val<(root->left)->value) return rightRotate(root);//left-left case
if(balance>1 && val>(root->right)->value) return leftRotate(root);//right-right case
if(balance<-1 && val>(root->left)->value) {root->left=leftRotate(root->left); return rightRotate(root);}//left-right case
if(balance>1 && val<(root->right)->value) {root->right=rightRotate(root->right); return leftRotate(root);}//right-left case

return root;
};

void preOrder(Node* root)
{
	if(root != NULL)
	{
		cout << root->value << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
};

int main()
{
  Node *root = NULL;

	/* Constructing tree given in
	the above figure */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

  cout << "Preorder traversal of the "
			"constructed AVL tree is \n";
	preOrder(root);

  return 0;
}
