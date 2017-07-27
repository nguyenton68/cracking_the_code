/*
Use 3 stacks for 1 array
- There are 3 arrays: 
  1. Original array arr[i]. This index i is important
  2. Top[i]: this array to store the top of a stack
  3. Next[i]: to in charge of next available element. This Next[i] relate to free variable
  i->free->next->top: for push
  i->top->next->free: for pop
*/
#include<iostream>
using namespace std;

class stacks{
  int *arr, *top, *Next;
  int free;
  int ns,N;
public:
  stacks(int,int);
  void push(int,int);
  int pop(int);
  bool isFull(){return (free==-1);};
  bool isEmpty(int ns){return (top[ns]==-1);};
};
stacks::stacks(int ns, int N)
{

  arr = new int[N];
  Next = new int[N];
  top = new int[ns];
  cout<<N<<"\t"<<ns<<endl;
  for(int i=0; i<N; i++)
    Next[i]= i+1;
  for(int j=0; j<ns; j++)
    top[j] = -1;

  free=0;
}
void stacks::push(int value, int ns)
{
  if(isFull())
    {
      cout<<"Stacks are fulled"<<endl;
      return;
    }
  int i= free;
  free = Next[i];
  Next[i] = top[ns];
  top[ns] = i;

  arr[i] = value;
}
int stacks::pop(int ns)
{
  if(isEmpty(ns))
    {
      cout<<"Stack is empty"<<endl;
      return;
    }
  int i = top[ns]; // lastest put in, added recently
  top[ns] = Next[i]; //should decrease by 1
  Next[i] = free;
  free = i;
  cout<<"Pooping this element= "<<arr[i]<<endl;
  return arr[i];
}
int main()
{
  int numStack=3;
  int size=10;
  stacks sk(numStack,size);

  sk.push(15,2);
  sk.push(45,2);


  sk.push(17,1);
  sk.push(49,1);
  sk.push(39,1);

  sk.push(11,0);
  sk.push(9,0);
  sk.push(7,0);

  sk.pop(1);
  sk.push(15,1);
  sk.pop(1);
}
