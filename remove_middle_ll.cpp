// 07/13/2017
// Remove the middle element of a link list wo using the head
// Sol:
// Copy the next node to the current node by using a temp node

#include <iostream>
using namespace std;
struct node
{
  char data;
  node *next;
} *start;
class link_list
{
public:
  node *create_node(char);
  void remove_mid(node*);
  void display();
  link_list()
  {
    start=NULL;
  };

};
int main()
{
  link_list ll;
  start = ll.create_node('a');
  start->next= ll.create_node('b');
  start->next->next= ll.create_node('c');
  start->next->next->next= ll.create_node('d');
  start->next->next->next->next= ll.create_node('e');
  start->next->next->next->next->next= ll.create_node('f');
  ll.display();
  cout<<"After remove the middle element"<<endl;
  ll.remove_mid(start->next->next->next);
  ll.display();
}
node * link_list::create_node(char value)
{
  node *tmp;
  tmp = new node;
  tmp->data = value;
  tmp->next = NULL;
  return tmp;
}
void link_list::display()
{
  node *tmp;
  tmp =start;
  while(tmp!=NULL)
    {
      cout<<tmp->data<<endl;
      tmp = tmp->next;
    }
}
void link_list::remove_mid(node*curr)
{
  node *tmp;
  tmp = curr->next;
  curr->data = tmp->data;
  curr->next = tmp->next;
  delete(tmp);

  // This is access the element by using pointer from head

  // int count=0;
  // curr = start;
  // while(curr!=NULL)
  //   {
  //     count++;
  //     curr = curr->next;
  //   }
  // cout<<"how many elements= "<<count<<endl;
  // int mid = int(count/2);
  // curr = start;
  // if(curr!=NULL)
  //   {
  //     for(int i=0; i<mid; i++)
  // 	{
  // 	  pre = curr;
  // 	  curr = curr->next;
  // 	}
  //     tmp = curr;
  //     pre->next = curr->next;
  //     curr = curr->next;
  //     delete(tmp);
  //   }
}
