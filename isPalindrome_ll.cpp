/* 
Check is a link list a Palindrome
Approach:
- Reverse second half and the list

Do:
1. Break a list into first and second half. Using fast and slow pointer.
When fast= null, mean this is even list, vice versa.
2. Careful with midnode.
3. Reverse second half.
4. Compare second half with first half
!!! first half is terminated by pre->next=NULL
and the original list is node *head. head is terminated.

5. Put first and second half back to orginial list.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node 
{
  int data;
  node *next;
};

node *create_node(int);
void print(node*);
/* Function to reverse a list. Caution: double pointer here */
void reverse(node**);
/* Function to return T/F when compare each element of two lists*/
bool checkPalindrome(node*,node*);
/* Check is it Palindrome:
Using fast and slow pointer*/
bool isPalindrome(node*);
int main()
{
  node *start=NULL;
  start=create_node(3);
  start->next = create_node(2);
  start->next->next = create_node(1);
  start->next->next->next = create_node(1);
  start->next->next->next->next = create_node(2);
  start->next->next->next->next->next = create_node(3);
  print(start);

  bool result = isPalindrome(start);
  cout<<"result is F or T= "<<result<<endl;
}
node *create_node(int value)
{
  node *tmp;
  tmp = new node;
  tmp->data = value;
  tmp->next = NULL;
  return tmp;
}
void print(node *tmp)
{
  while(tmp!=NULL)
    {
      cout<<tmp->data<<endl;
      tmp = tmp->next;
    }
}

void reverse(node **head)
{
  node *pre=NULL, *cur=*head, *Next;//=NULL;

  while(cur != NULL)
    {
      Next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = Next;
    }
  *head = pre;
}

bool checkPalindrome(node *l1, node *l2)
{
  node *temp1,*temp2;
  temp1 = l1;
  temp2 = l2;

  while( temp1!=NULL && temp2!=NULL)
    {
      cout<<temp1->data<<" l2= "<<temp2->data<<endl;
      if(temp1->data == temp2->data)
	{
	  temp1 = temp1->next;
	  temp2 = temp2->next;
	}
      else 
	{
	return 0;
	}
    }
 return temp1==NULL && temp2 == NULL;
}

bool isPalindrome(node *head)
{
  node *slow_ptr = head, *fast_ptr = head;
  node *second_half, *pre_of_slow_ptr=head;
  node *midnode=NULL;
  bool res = true;

  if(head!=NULL && head->next!=NULL)
    {
      while(fast_ptr != NULL && fast_ptr->next != NULL)
	{
	  fast_ptr = fast_ptr->next->next;

	  pre_of_slow_ptr = slow_ptr;
	  slow_ptr = slow_ptr->next;
	}
      if(fast_ptr != NULL)
	{
	  midnode = slow_ptr;
	  slow_ptr = slow_ptr->next;
	}
      second_half = slow_ptr;
      /* Terminate head here! Interesting!!!*/
      pre_of_slow_ptr->next=NULL;
      reverse(&second_half);
      res = checkPalindrome(head,second_half);

      reverse(&second_half);

      if(midnode != NULL)
	{
	  pre_of_slow_ptr->next = midnode;
	  midnode->next = second_half;
	}
      else pre_of_slow_ptr->next = second_half;
    }
  return res;
}
