/*
08/01/2017
Check a binary tree is a binary seach tree BST or not.
- Use inorder transverse.
- Use a global variable to save the previous data
- Then check if the previous > current data or not

Caution:
- Void function with return
 */
#include<iostream>
#include<climits>
using namespace std;

const int N=7;
int indx=0;
struct node
{
  int data;
  node *left;
  node *right;
};
node *create_node(int value)
{
  node *tmp = new node;
  tmp->data = value;
  tmp->left = NULL;
  tmp->right = NULL;

  return tmp;
}
void copyBST(node*, int*);
void isBST(node*);
int main()
{
  node *root = new node;
  root = create_node(14);
  root->left = create_node(15);
  root->right = create_node(22);
  root->left->left = create_node(1);
  root->left->right = create_node(17);
  root->right->left = create_node(21);
  root->right->right = create_node(45);

  //  bool res;
  isBST(root);
  //  cout<<"the tree is BST or NOT T/F "<<res<<endl;
}

void isBST(node *root2)
{
  if(root2 == NULL) return;

  isBST(root2->left);

  if(indx != 0 && root2->data < indx)
    {
      cout<<"not BST"<<endl;
      return;
    }
  indx = root2->data;

  isBST(root2->right);
    return;
}
