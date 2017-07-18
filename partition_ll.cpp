/*
07/17/2017
- Partition a link list into a small and large compare with a pivot
- Create 3 lists. Each list has a head and a tail.
 Loop through the main list: if data< pivot, connect the node to the small list... by using the Tail
Tail = Tail->next // tail is the pointer moving not the Head
- Then combine 3 lists together: smallTail->next = equalHead, etc.
*/
#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
}*start;
node *create_node(int);
node *partition(node*,int);
void display(node*);

int main()
{

  start = create_node(3);
  start->next = create_node(5);
  start->next->next = create_node(2);
  start->next->next->next = create_node(10);
  start->next->next->next->next = create_node(7);
  start->next->next->next->next->next = create_node(4);
  start->next->next->next->next->next->next = create_node(5);
  display(start);
  cout<<"After sort= "<<endl;
  int x = 7;
  start = partition(start, x);
  display(start);
}
node *create_node(int value)
{
  node *tmp;
  tmp = new node;
  tmp->data = value;
  tmp->next=NULL;
  return tmp;
}
void display(node *start)
{
  node *temp;
  temp =start;
  while(temp!=NULL)
    {
      cout<<temp->data<<endl;
      temp = temp->next;
    }
}
node *partition(node *start, int pivot)
{
  node *smallHead=NULL,*smallTail=NULL;
  node *equalHead=NULL,*equalTail=NULL;
  node *largeHead=NULL,*largeTail=NULL;
  while(start!=NULL)
    {
      if(start->data == pivot)//equal list
	{
	  if(equalHead==NULL)
	      equalHead=equalTail =start;
	  else
	    {
	      equalTail->next = start;
	      equalTail = equalTail->next;
	    }
	}
      else if(start->data < pivot)//small list
	{
	  if(smallHead==NULL)
	    smallHead = smallTail = start;
	  else
	    {
	      smallTail->next = start;
	      //smallTail = start;
	      smallTail = smallTail->next;
	    }
	}
      else
	{
	  if(largeHead==NULL)//large list
	    largeHead = largeTail = start;
	  else
	    {
	      largeTail->next = start;
	      largeTail = largeTail->next;
	    }
	}
      start = start->next;
    }
  if(largeTail!=NULL)//check large tail is NULL
    largeTail->next = NULL;
  if(smallHead==NULL)//check if there is no small list
    {
      if(equalHead==NULL)//check if there is no equal list
	return largeHead;
      equalTail->next = largeHead;
      return equalHead;
    }
  if(equalHead==NULL)
    {
      smallTail->next = largeHead;
      return smallHead;
    }
  smallTail->next = equalHead;
  equalTail->next = largeHead;
  return smallHead;
} 
