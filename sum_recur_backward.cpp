/* Sum two 2 link lists each digit, with the significant digit is at the head
   1. Compare 2 lists length.
   2. Add zero to the short list to make them same length.
   3. Recursive call addListHelper to reach tail.
   4. Add sum after reach tail.

   Problem:
   Right result but there is segmentation fault!!!
NULL somewhere
 */
#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
struct partialSum
{
  node *sum;
  int carry=0;// 1 warning here
};

node *create_node(int);
int size(node*);
node *insertBefore(node*, int);
node *padList(node*, int);
partialSum *addListHelper(node*, node*);
node *addList(node*, node*);
void print(node*);
int main()
{
  node *l1 = NULL;
  l1 = create_node(7);
  l1->next = create_node(2);
  l1->next->next = create_node(4);
  print(l1);

  node *l2 = NULL;
  l2 = create_node(5);
  l2->next = create_node(1);
  l2->next->next = create_node(6);
  cout<<"list 2="<<endl;
  print(l2);

  cout<<"sum of 2 lists="<<endl;
  node *FinalResult=NULL;
  FinalResult =addList(l1,l2);
  print(FinalResult);
}
node *create_node(int value)
{
  node *tmp = new node;
  tmp->data = value;
  tmp->next = NULL;
  return tmp;
}
int size(node *temp)
{
  int length =0;
  while(temp!=NULL)
    {
      length++;
      temp = temp->next;
    }
  return length;
}
void print(node *tmp)
{
  while(tmp!=NULL)
    {
      cout<<tmp->data<<endl;
      tmp = tmp->next;
    }
}
node *padList(node *head, int LenDiff)
{
  node *tmp;
  tmp = head;

  for(int i=0; i<LenDiff; i++)
    {
      tmp = insertBefore(tmp,0);
    }
  return tmp;
}

/* Insert zero before a list
 1-> 2-> 3-> NULL
 0-> 1-> 2-> 3-> NULL */
node *insertBefore(node *head, int number)
{
  node *tmp = create_node(number);
  tmp->next = head;
  return tmp;
}
partialSum *addListHelper(node *l1, node *l2)
{
  if(l1==NULL && l2==NULL)
    {
      partialSum *sum = new partialSum;
      return sum;
    }

  partialSum *sum = addListHelper(l1->next, l2->next);
  int val = sum->carry + l1->data + l2->data;
  node *result = insertBefore(sum->sum, val%10);

  sum->sum = result;
  sum->carry = val/10;

  return sum;
}
node *addList(node *l1, node *l2)
{
  int len1 = size(l1);
  int len2 = size(l2);
/* Compare 2 lists length:
   Pad zero to begining of the smaller list
*/
  if(len1<len2)
    l1 = padList(l1,0);
  else if(len2<len1)
    l2 = padList(l2,0);

  /*Add each digit from the last node by using recursively call  */
  partialSum *sum = addListHelper(l1,l2);

  /* Take care carry of sum of the first node, >10 or <10 */
  if(sum->carry == 0)
    return sum->sum;
  else
    {
      node *result = insertBefore(sum->sum, sum->carry);
      return result;
    }
}
