#include<iostream>
#include<cmath>
using namespace std;
float power(float num1,float num2);
main()
{
    float num1,num2;
    cout<<"Enter the base number: ";
    cin>>num1;
    cout<<"Enter the exponent number: ";
    cin>>num2;
    float result;
    result=power(num1,num2);
    cout<<num1<<" raised to the power "<<num2<<" is: "<<result;
}
float power(float num1,float num2)
{
    float power;
    power=pow(num1,num2);
    return power;
}