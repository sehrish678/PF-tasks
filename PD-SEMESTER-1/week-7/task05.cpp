#include<iostream>
#include<cmath>
using namespace std;
bool prime(int num);
main()
{
    int num;
    cout <<"Enter Number: ";
    cin>>num;
    int result;
    result =prime(num);
    cout<<result;
}
bool prime(int num)
{   if(num <2)
{
    return false;
}
     for(int x=2;x <= num;x++)
     {
        if(num%2 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
     }
}
