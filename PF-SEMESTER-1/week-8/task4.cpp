#include<iostream>
using namespace std;
bool isPrime(int num);
main()
{    int count;
    int num;
    cout<<"Enter the number: ";
    cin>>num;
bool result=isPrime(num);
if(result==true)
{
    count++;
}
cout<<count;

}
bool isPrime(int num)
{   
    if(num <2)
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

