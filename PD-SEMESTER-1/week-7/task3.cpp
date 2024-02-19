#include<iostream>
using namespace std;
int amplifiednum(int num);
main()
{
int num;
cout<<"Enter the number: ";
cin>>num;
amplifiednum(num);
}
int amplifiednum(int num)
{
    for(int i=1;i<=num;i++)
    {   if(i%4==0)
       {int j;
        j=i*10;
        cout<<j<<",";
       }
       else{
       cout<<i<<",";
       }
       
    }
}
