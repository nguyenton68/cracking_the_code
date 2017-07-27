/* 
Queue using 2 stacks
- stack1 use for enQueue, push new data into top of stack1
- stack2 use for deQueue, pop data from top of stack2.
  if (stack2 empty) put data from stack1 to stack2
*/
#include<iostream>
using namespace std;
struct node
{
  node *next;
  int data;
};
struct queue
{
  node *stack1;
  node *stack2;
};
void push(node**,int);
int pop(node**);
void enQueue(queue*,int);
int deQueue(queue*);

int main()
{
  queue *qq=(queue*)malloc(sizeof(queue));
  qq->stack1 = NULL;
  qq->stack2 = NULL;
  enQueue(qq,1);
  enQueue(qq,2);
  enQueue(qq,3);
  enQueue(qq,4);

  int pop_out=deQueue(qq);
  cout<<"remove 1 element= "<<pop_out<<endl;
  cout<<"remove 1 element= "<<deQueue(qq)<<endl;
  cout<<"remove 1 element= "<<deQueue(qq)<<endl;
}

void push(node **head, int value)
{
  node *tmp = (node*)malloc(sizeof(node));
  tmp->data = value;
  tmp->next = *head;
  *head = tmp;
}
int pop(node **head)
{
  node *tmp;
  int res;
  tmp = *head;
  res = tmp->data;
 
  *head = tmp->next;

  delete tmp;
  return res;
}
void enQueue( queue *q, int value)
{
  push(&q->stack1, value);
}
int deQueue(queue *q)
{
  if(q->stack1 == NULL && q->stack2==NULL)
    return 0;
  if(q->stack2 == NULL)
    {
      /* while stack1 is not empty */
      while(q->stack1 != NULL)
	{
	  int val = pop(&q->stack1);
	  push(&q->stack2,val);
	}
    }
  int temp = pop(&q->stack2); 
  return temp;
}
