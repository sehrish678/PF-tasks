#include<iostream>
using namespace std;
string reverseorder(string name);
main()
{
string name;
cout<<"Enter a string: ";
cin>>name;
reverseorder(name);
}
string reverseorder(string name)
{   int length;
 cout<<"Reversed String: ";
    for(int x=4;x>=0;x--)
    {
       cout<< name[x];
    } 
    
}