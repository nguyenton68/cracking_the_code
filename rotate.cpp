// 07/09/2017
// 
// Rotate counter clockwise 90 deg
// By using 2D array nxn
#include <iostream>
#include <string>
using namespace std;
const int DIM=4;
void printArr(int[][DIM], int);
int main()
{
  int a[DIM][DIM];
  int count=0;
  for(int i=0; i<DIM; i++)
    {
      for(int j=0; j<DIM; j++)
	{
	  a[i][j]=count;
	  count++;
	}
    }
  printArr(a,DIM);

  // Rotate 2D array
  for(int layer=0; layer<DIM/2 ; layer++)
    {
      int last = DIM-layer-1;
      int first = layer;
      for(int i=first; i<DIM-1; i++)
	{
	  int offset = i-first;

	  int tmp = a[first][i];
	  a[first][i]= a[i][last];
	  a[i][last] = a[last][last-offset];
	  a[last][last-offset] = a[last-offset][first];
	  a[last-offset][first] = tmp;
	}
    }
  cout<<"After"<<endl;
  printArr(a,DIM);
}
void printArr(int arr[][DIM], int size)
{
  for(int i=0; i<size; i++)
    {
      for(int j=0; j<size; j++)
	cout<<arr[i][j]<<"\t";
      cout<<endl;
    }
}
