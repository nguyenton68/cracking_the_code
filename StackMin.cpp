/* Implement min() function to return min of a stack with O(1) space
- This method uses array
- push(value): if find a min, put (2*min-value) into stack and save min = value
- Pop(): if the value at the stack is smaller than min, then return 
min = 2*min - value;// this is the real current mean
 */
#include<iostream>
using namespace std;

const int N=10;
class stackMin
{
  int minEle;
  int top;
  int *arr;
public:
  stackMin();
  void push(int);
  void pop();
  void min();
};
stackMin::stackMin()
{
  minEle = 10000;
  top = -1;
  arr = new int[N];
}
void stackMin::push(int value)
{

  if(value < minEle)
    {
      arr[top] = 2*minEle -value;
      minEle = value;
    }
  else
    arr[top] = value;
  top++;
}
void stackMin::pop()
{
  if(arr[top] < minEle)
      minEle = 2*minEle -arr[top];
  top--;
}
void stackMin::min()
{
  cout<<"minimum element= "<<minEle<<endl;
}
int main()
{
  stackMin sm;
  sm.push(4);
  sm.push(9);
  sm.push(0);
  sm.push(10);

  sm.min();
}
