#include<iostream>
using namespace std;
main()
{
    int num1,num2;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;
    if(num1>num2)
    {
        cout<<"The minimum of "<<num1<<" and "<<num2<<" is: "<<num2;
    }
    else if(num2>num1)
    {
        cout<<"The minimum of "<<num1<<" and "<<num2<<" is: "<<num1;
    }
}