#include<iostream>
using namespace std;
int primoral(int num);
bool isprime(int num);
main()
{
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    int result;
    result=primoral(num);
    cout<<result;
}
bool isprime(int num)
{
    if(num < 2)
    {
        return false;
    }
for(int x = 2;x< num;x++)
    {
        if(num%x==0)
        {
            return false;
        }
    }
      return true;
}
int primoral(int num)
{
    int multiply=1;
    int i=2;
    while(num!=0)
    {  
         if(isprime(i))
       {
        multiply=multiply*i;
        num= num-1;
       }
        i++;
        
    }
    return multiply;
}
