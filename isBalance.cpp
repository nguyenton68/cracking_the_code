/*
Check is a tree balance?
- Use recursive getHeight, to get height of each node
- If any node have height difference between left and right is more than 1, then return false
Caution:
- How to return the base (leaf): return -1 for getHeight and return true for isBalance.
 */

#include<iostream>
#include<algorithm>
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
int getHeight(node*);
bool isBalance(node*);
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

  root->left->left->left = create_node(3);
  root->left->left->right = create_node(4);
  root->left->right->left = create_node(5);
  cout<<"Height of the tree= "<<getHeight(root)<<endl;
  cout<<"is balance tree T/F= "<<isBalance(root)<<endl;
}
int getHeight(node *root1)
{
  if(root1 == NULL) return -1;
  return max(getHeight(root1->left), getHeight(root1->right))+1;
}
bool isBalance(node *root1)
{
  if(root1 == NULL)
    return true;
  int diff_node = abs(getHeight(root1->left) - getHeight(root1->right));
  if(diff_node >1)
    return false;
  else
    {
      return (isBalance(root1->left) && isBalance(root1->right));
    }
}
