// Find the kth to the last
// Use recursive call

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

int printKth(node*, int);
node *create_node(int);
int main()
{

  node *start;
  start=NULL;
  start=create_node(1);
  start->next = create_node(5);
  start->next->next= create_node(26);
  start->next->next->next = create_node(2);
  start->next->next->next->next = create_node(1);
  start->next->next->next->next->next = create_node(9);

  int indx = printKth(start,4);
  cout<<indx<<endl;
}
node *create_node(int value)
{
  node *tmp;
  tmp = new node;
  tmp->data = value;
  tmp->next = NULL;
  return tmp;
}
int printKth(node *tmp, int k)
{
  if(tmp==NULL)
    return 0;
  int index = printKth(tmp->next,k)+1;
  if(index==k)
    cout<<"reach the kth element value= "<<tmp->data<<endl;
  
  return index;
}
