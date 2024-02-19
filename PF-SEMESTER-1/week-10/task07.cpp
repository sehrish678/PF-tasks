#include<iostream>
using namespace std;
main()
{  
int num1;
cout<<"Enter the number of resistors in the series circuit: ";
cin>>num1;
double arr[num1];
cout<<"Enter the resistance values (in ohms) of the "<<num1<<" resistors,"<<" one per line: "<<endl;
double sum=0;
for(int x=1;x<=num1;x++)
{
    cin>>arr[x];
    
sum=arr[x]+sum;}
    cout<<"The total resistance of the series circuit is "<<sum<<" ohms.";
}