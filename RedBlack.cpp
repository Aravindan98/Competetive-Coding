#include<iostream>

using namespace std;

typedef struct node
{
  int key;
  node* left;
  node* right;
  int balance;
}node;

class RBTree
{
private:
  int size;
  node* root;

public:
  RBTree();
  leftRotate();
  rightRotate();
};

RBTree::RBTree()
{
  size=0;
  root=NULL;
}

int main()
{
  return 0;
}
