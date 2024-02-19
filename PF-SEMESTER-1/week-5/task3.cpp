#include<iostream>
#include<cmath>
using namespace std;
float myfunction(float num);
main()
{
float num;
cout<<"Enter a number: ";
cin>>num;
float result;
result=myfunction(num);
cout<<"The square root of "<<num<<" is: "<<result;
}
float myfunction(float num)
{
    float square;
    square=sqrt(num);
    return square;
}