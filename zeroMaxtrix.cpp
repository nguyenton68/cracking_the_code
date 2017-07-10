// 07/09/2017
// Problem:
// Zero all elements in ith row and jth column of an array if a[i][j]=0
// Solution:
// Don't be cheated and zero the whole matrix
// Use 2 separate arrays to store index
// Then loop through each array and zero all elements in that row/column
#include <iostream>
using namespace std;

const int DIM=5;
void printArr(int[][DIM]);
int main()
{
  int a[DIM][DIM]={
    {1,8,9,2,3},
    {5,7,9,0,3},
    {5,4,3,2,1},
    {0,8,6,5,4},
    {7,4,1,6,7}
  };
  printArr(a);
  bool row[DIM]={0};
  bool column[DIM]={0};
  for(int i=0; i<DIM; i++)
    {
      for(int j=0; j<DIM; j++)
	{
	  if(a[i][j]==0)
	    {
	      row[i]=true;
	      column[j]=true;
	      cout<<i<<"\t j"<<j<<endl;
	    }
	}
    }
  for(int i=0; i<DIM; i++)
    {
      if(row[i])
	{
	  for(int l=0; l<DIM; l++)
	      a[i][l]=0;
	  cout<<"inside row"<<i<<endl;
	}
      if(column[i])
	{
	  for(int k=0; k<DIM; k++)
	    a[k][i]=0;
	}
    }
  cout<<"After"<<endl;
  printArr(a);
}
void printArr(int array[][DIM])
{
  for(int i=0; i<DIM; i++)
    {
      for(int j=0; j<DIM; j++)
	cout<<array[i][j]<<"\t";
      cout<<endl;
    }
}
