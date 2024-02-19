#include<iostream>
using namespace std;
bool Parity(int num,int sum);
main()
{
    int num;
    int sum=0;
    cout<<"Enter a 3-digit number: ";
    cin>>num;
    bool result;
   result=Parity(num,sum);
   cout<<result;
}
bool Parity(int num,int sum)
{
     while(num!=0)
    {
        int mode=num%10;
        num=num/10;
        sum=mode+sum;

    }
    if((num%2==0) && (sum%2==0))
    {
        return true;
    }
    else if((num%2!=0) && (sum%2!=0))
    {
        return true;
    }
    else{
        return false;
    }
}