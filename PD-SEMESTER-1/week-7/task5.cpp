#include<iostream>
using namespace std;
bool isprime(int num);
main()
{
int num;
cout<<"Enter a number: ";
cin>>num;
int result;
result=isprime(num);
cout<<result;
}
bool isprime(int num)
{
    if(num < 2)
    {
        return false;
    }
for(int x = 2;x<= num;x++)
    {
        if(num%x==0)
        {
            return false;
        }
        else{
            return true;
        }
    }

}
     