// Sum 2 link lists, digit by digit
// Forward order
// Caution: 
// How to treat the last element sum>10?
// SOL: use while loop

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
}*start1,*start2;
node *create_node(int);
node *addTwoLists(node*, node*);
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
  start2->next->next = create_node(4);
  cout<<"List 2:"<<endl;
  print(start2);

  node *res;
  res = addTwoLists(start1,start2);
  cout<<"Sum of 2 lists:"<<endl;
  print(res);
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
node *addTwoLists(node *l1, node *l2)
{
  node *res = NULL;
  node *temp, *pre=NULL;
  int carry=0;
  int sum;
  while(l1!=NULL || l2!=NULL)
    {
      sum = carry+ (l1 ? l1->data : 0) + (l2 ? l2->data : 0);
      carry = (sum>10) ? 1 : 0;
      sum = sum%10;
      temp = create_node(sum);
      if(res==NULL)
	res = temp;//head to the list
      else
	/*temp is an alone node, it does not have a link
so we need to have another pointer (pre) to link the list  */
	pre->next = temp;//link each node

      pre = temp;
      if(l1) l1 = l1->next;
      if(l2) l2 = l2->next; 
    }
  if(carry>0)
    temp->next = create_node(carry);
  
  return res;
}
