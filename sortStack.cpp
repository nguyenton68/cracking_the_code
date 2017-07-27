/*Sort a stack
- use 2 stacks: input & tmpStack
- while (input is not empty)
    get the top element: tmp = input.top()
    while (tmpStack is not empty && tmpStack.top() > tmp)
       pop out of tmpStack and push into input
   push tmp into tmpStack
 */
#include<iostream>
#include<stack>
using namespace std;

stack<int> sortStack(stack<int> input)
{
  stack<int> tmpStack;
  while(!input.empty())
    {
      int tmp = input.top();
      input.pop();
      while( !tmpStack.empty() && (tmpStack.top() > tmp) )
	{
	  input.push(tmpStack.top());
	  tmpStack.pop();
	}
      tmpStack.push(tmp);
    }
  return tmpStack;
};
void print(stack<int> temp)
{
  while( !temp.empty())
    {
      cout<<"Stack sequence= "<<temp.top()<<endl;
      temp.pop();
    }
}
int main()
{
  stack<int> sk;
  sk.push(34);
  sk.push(3);
  sk.push(31);
  sk.push(98);
  sk.push(92);
  sk.push(23);
  print(sk);
  cout<<"After sort="<<endl;
  stack<int> result = sortStack(sk);
  print(result);
}
