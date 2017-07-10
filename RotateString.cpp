// Problem:
// Check if string s1 is a rotation of string s2
// Solution:
// s1 must be a substring of s3 = s2s2
#include <iostream>
#include <string>
using namespace std;
int main()
{
  string s1="waterbottle";
  string s2="erbottlewat";
  string s3 = s2+s2;
  if(s3.find(s1))
    cout<<"is a substring"<<endl;
}
