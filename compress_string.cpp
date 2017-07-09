// Compress a string by counting how many times a char appear
// Use char to concate a number into a string
// 07/09/2017

#include <string>
#include <iostream>
using namespace std;
int main()
{
  string str_in="aabcccccaaa";
  string str_out="";
  int countChar=0;
  char NumChar[20];
  for(int i=0; i<str_in.length(); i++)
    {
      countChar++;
      if(str_in[i]!=str_in[i+1])
	{
	  sprintf(NumChar,"%d",countChar);
	  str_out=str_out+str_in[i]+NumChar;
	  countChar=0;
	}
    }
  if(str_in.length()<=str_out.length())
    cout<<"in= "<<str_in<<endl;
  else
    cout<<"out= "<<str_out<<endl;
}
