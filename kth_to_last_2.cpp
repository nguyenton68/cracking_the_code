// Get kth to the last (position kth count from the last element)
// 2 pointers: the distance between 2 pointers = k;
// When p1 = 0(head), p2 = kth
//   |-------x---|
//   p1      p2
//  head
//   |---x-------|
//       p1      p2
//               tail
// When p2 = NULL (length of the list), p1 = len-k
#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
}*start;

int printKth(node*, int);
node *create_node(int);
int main()
{
  start=create_node(1);
  start->next = create_node(5);
  start->next->next= create_node(26);
  start->next->next->next = create_node(2);
  start->next->next->next->next = create_node(1);
  start->next->next->next->next->next = create_node(9);

  int kthValue = printKth(start,4);
  cout<<kthValue<<endl;
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
  node *p1,*p2;
  p1 = start;
  p2 = start;

  for(int i=1; i<k; i++)
    {
      p1 = p1->next;
    }
  while(p2!=NULL)
    {
      p2 = p2->next;
      p1 = p1->next;
      if(p1->next==NULL)
	break;
    }
  return p2->data;
}
