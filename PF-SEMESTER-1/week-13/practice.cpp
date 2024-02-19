#include<iostream>
#include<typeinfo>
using namespace std;
bool ValidOrNot(int num);
main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    bool result=ValidOrNot(num);
    cout<<result;
}

bool ValidOrNot(int num)
{   int b;
     if((typeid(num).name())==(typeid(b).name()))
     {
        return true;
     }
     else {
        return false;
     }
}
