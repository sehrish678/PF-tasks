#include<iostream>
using namespace std;
string Postmortem(string name);
main()
{
string name;
cout<<"Enter a word: ";
cin>>name;
Postmortem(name);
}
string Postmortem(string name)
{
    for(int x=0;name[x]!='\0';x++)
    {
        cout<<name[x]<<" found at position "<<x<<endl;
    }
}
