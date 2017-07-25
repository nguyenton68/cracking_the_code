/* 
Get intersection of 2 link lists:
1. diff = len1 - len2: the difference in length of 2 lists
2. Move the head of the long list N=diff time.
3. Start to loop through the list to see are the 2 POINTERS (not ->data) the same

 */
#include<iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
int size(node*);
node *moveLongList(int, node*);
int getIntersection(node*, node*);
int main()
{

}
int size(node *head)
{
  node *temp = head;
  int count=0;
  while(temp != NULL)
    {
      count++;
      temp = temp->next;
    }
  return count;
}
node *moveLongList(int diff, node *head)
{
  node *temp = head;
  for (int i=0; i<diff; i++)
    {
      temp = temp->next;
    }
  return temp;
}
node *getIntersection(node *head1, node *head2)
{
  node *tmp1=head1, *tmp2 = head2;
  node *res;
  int diff=0;
  int len1 = size(tmp1);
  int len2 = size(tmp2);
  diff = abs(len1-len2);
  if(len1 > len2)
    {
      res = moveLongList(diff,tmp1)
    }
  else
    res = moveLongList(diff,tmp2)
      while(tmp1 != NULL && tmp2 != NULL)
	{

	  if(tmp1 == tmp2)
	    return 1;
	  tmp1 = tmp1->next;
	  tmp2 = tmp2->next;
	}
  return 0;
}
