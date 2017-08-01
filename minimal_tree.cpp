/* create BST from a sorted array
- Get the mid element, set this to be root node
- recursively call this function for the left and the right

Be careful with indices
 */
#include<iostream>
#include<cstdlib>
const int N=7;

using namespace std;

struct node
{
  int data;
  node * left;
  node *right;
};

node *create_node(int);
node *minimal_tree(int [],int,int);
int main()
{
  int arr[N] ={1,3,5,7,8,9,10};
  node *res =(node*)malloc(sizeof(node));
  res =  minimal_tree(arr,0,N-1);

  return 0;
}
node *create_node(int value)
{
  node *tmp = (node*)malloc(sizeof(node));
  tmp->right = NULL;
  tmp->left = NULL;
  tmp->data = value;

  return tmp;
}
/*
call recursively for left and right
 */
node *minimal_tree(int arr[], int start, int end)
{
  if(start>end)
    return NULL;

  int mid=(end+start)/2;
  node *root = create_node(arr[mid]);

  root->left =  minimal_tree(arr,start,mid-1);
  root->right = minimal_tree(arr, mid+1, end);

  return root;
}
