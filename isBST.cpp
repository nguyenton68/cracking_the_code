/*
08/01/2017
Check a binary tree is a binary seach tree BST or not.
- Use inorder transverse.
- Copy root->data into an array
- Then check is the array sorted

Caution:
- Array index when do checking... a[i]> a[i+1]. This i+1 is out of the range
- When call copyBST(), need to test root != NULL
 */
#include<iostream>

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
bool isBST(node*);
int main()
{
  node *root = new node;
  root = create_node(20);
  root->left = create_node(15);
  root->right = create_node(22);
  root->left->left = create_node(1);
  root->left->right = create_node(17);
  root->right->left = create_node(21);
  root->right->right = create_node(45);

  bool res;
  res = isBST(root);
  cout<<"the tree is BST or NOT T/F "<<res<<endl;
}
void copyBST(node *root1, int *arr)
{
  if(root1 != NULL)
    {
      copyBST(root1->left, arr);
      arr[indx] = root1->data;
      indx++;
      copyBST(root1->right, arr);
    }
}
bool isBST(node *root2)
{
  int *arr;
  arr = new int[N];
  if(root2 == NULL)
    {
      cout<<"empty"<<endl;
      return false;
    }
  copyBST(root2, arr);

  for(int i=0;i<N; i++)
    {
      cout<<arr[i]<<endl;
      if(arr[i] > arr[i+1] && (i+1) < N)       
	return false;       
    }
  
  return true;
}
