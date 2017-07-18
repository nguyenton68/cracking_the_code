// Sum 2 link lists, digit by digit
// Create a node for result, then link result node by ->next. Call recursively
// Use an int to carry the value either 1 or 0
#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
}*start1,*start2;
node *create_node(int);
node *sum(node*, node*, int);
void print(node*);
int main()
{
  cout<<"List 1:"<<endl;
  start1 = create_node(7);
  start1->next = create_node(1);
  start1->next->next = create_node(6);
  print(start1);
  start2 = create_node(5);
  start2->next = create_node(9);
  start2->next->next = create_node(2);
  cout<<"List 2:"<<endl;
  print(start2);
  node *output;
  start1 = sum(start1,start2,0);
  cout<<"Sum of 2 lists:"<<endl;
  print(start1);
}
node *create_node(int value)
{
  node *tmp;
  tmp = new node;
  tmp->data = value;
  tmp->next= NULL;
  return tmp;
}
void print(node *start1)
{
  node *tmp;
  tmp =start1;
  while(tmp!=NULL)
    {
    cout<<tmp->data<<endl;
    tmp = tmp->next;
    }
}
node *sum(node *l1, node *l2, int carry)
{
  node *result;
  result = new node;
  if(l1==NULL&&l2==NULL&&carry==0)
    return NULL;
  int value;
  value = carry;
  if(l1!=NULL)
    value+=l1->data;
  if(l2!=NULL)
    value+= l2->data;
  cout<<"sum of each digit"<<value<<endl;
  int sum_ll = value%10;
  if(l1!=NULL&&l2!=NULL)
    {
      node *temp =sum(l1==NULL ? NULL : l1->next,
		  l1==NULL ? NULL : l2->next,
		  value>10 ? 1 : 0);
      result->data = sum_ll;//save the data
      result->next = temp;// connect the link
    }
  return result;
}
