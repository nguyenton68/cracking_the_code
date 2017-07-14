// 07/13/2017
// Remove duplicate elements in a link list using hash table
// Loop through the list and put data into a hash int table
// Remove any element which already in the table

#include <iostream>
#include <unordered_set>
using namespace std;
struct node
{
  int data;
  node *next;
} *start;
class link_list
{
public:
  node * create_node(int);
  void display();
  void remove_hash();
  link_list()
  {
    start=NULL;
  };
};
int main()
{
  link_list ll; 
  start = ll.create_node(1);
  start->next = ll.create_node(9);
  start->next->next = ll.create_node(7);
  start->next->next->next = ll.create_node(9);
  start->next->next->next->next = ll.create_node(5);
  ll.display();
  cout<<"After delete duplicate elements"<<endl;
  ll.remove_hash();
  ll.display();
}
node * link_list::create_node(int value)
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
      tmp =tmp->next;
    }
}
void link_list::remove_hash()
{
  node *pre, *cur;
  cur = start;
  unordered_set<int> box;
  while(cur!=NULL)
    {
      if(box.find(cur->data) != box.end())
	{
	  pre->next = cur->next;
	  delete(cur);
	}
      else
	{
	  pre = cur;
	  box.insert(cur->data);
	}
      cur = cur->next;
    }
}
