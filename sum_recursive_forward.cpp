/*
Forward summing 2 lists (single link list) with the least significant digit at the head
- Recursively call the sum() function
- Problem: after run several times, it give segmentation fault
 */
#include <iostream>
using namespace std;
struct node
{
  int data;
  node* next;
}*start1=NULL,*start2=NULL;
node *create_node(int);
void print(node*);
node *sum(node*,node*,int);
int main()
{
  /* List 1 */
  start1 = create_node(7);
  start1->next = create_node(1);
  //  start1->next->next = create_node(5);
  print(start1);
  /* List 2 */
  start2 = create_node(4);
  start2->next = create_node(3);
  start2->next->next = create_node(6);
  cout<<"List 2="<<endl;
  print(start2);

  cout<<"sum of 2="<<endl;
  node *res;
  res = sum(start1,start2,0);
  print(res);
}
node *create_node(int value)
{
  node *temp;
  temp = new node;
  temp->data = value;
  temp->next = NULL;
  return temp;
}
void print(node *List)
{
  while(List!=NULL)
    {
      cout<<List->data<<endl;
      List = List->next;
    }
}
node *sum(node *l1, node *l2, int carry)
{
  int value;
  /*Why have to malloc?  */
  node *result=(node*)malloc(sizeof(node));
  value =carry;

  if(l1==NULL && l2==NULL && carry==0)
    return NULL;

  
  if(l1!=NULL)
    value += l1->data;
  if(l2!=NULL)
    value += l2->data;

  result->data = value%10;
  /* Recursive call  */
  if(l1!=NULL || l2!=NULL)
    {
      node *tmp = sum(l1? l1->next :0,l2 ? l2->next:0, (value>10)?1 :0);      
      result->next = tmp;/* Link to the list */
    }
  return result;
}
