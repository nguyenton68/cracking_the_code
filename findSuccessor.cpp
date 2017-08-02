/*
Find successor of a node
- If node->right != NULL, find the left most node
- Else: go backward until parent == node->left, by using 2 pointers.

If I don't initialize root = NULL in main program, it causes segmentation fault.
 */
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
  int data;
  node *left;
  node *right;
  node *parent;
};
node *create_node(int value)
{
  node *tmp = new node;
  tmp->data = value;
  tmp->left = NULL;
  tmp->right = NULL;
  tmp->parent = NULL;

  return tmp;
}
node *insert(node*, int);
node *leftMost(node*);
node *successor(node*);
int main()
{
  node *root = NULL;
  node * temp;
  root = insert(root,14);
  root = insert(root,15);
  root = insert(root,22);
  root = insert(root,10);
  root = insert(root,17);
  root = insert(root,21);
  root = insert(root,45);
  root = insert(root,13);
  root = insert(root,41);
  root = insert(root,5);
  temp = root->right->right;//->left;
  node *res;
  res = successor(temp);
  cout<<temp->data<<" is smaller than= "<<res->data<<endl;
}
node *insert(node *root1, int val)
{
  if(root1 == NULL)
    return create_node(val);
  else
    {
      node *tmp;
      if(val < root1->data)
	{
	  tmp = insert(root1->left, val);
	  root1->left = tmp;
	  tmp->parent = root1;
	}
      else
	{
	  tmp = insert(root1->right, val);
	  root1->right = tmp;
	  tmp->parent = root1;
	}
      return root1;
    }
}
node *leftMost(node *root1)
{
  node *tmp = root1;
  while(tmp->left != NULL)
    {
      tmp = tmp->left;
    }
  return tmp;
}
node *successor(node *root1)
{
  node *tmp;
  if(root1->right != NULL)
    {
      return (leftMost(root1->right));
    }
  else
    {
      tmp = root1;
      node *x = tmp->parent;
      while( x != NULL && tmp != x->left)
	{
	  tmp =x;
	  x = x->parent;
	}
      return x;  
    } 
  
}
