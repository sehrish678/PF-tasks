#include<iostream>
using namespace std;
int numofdots(int num);
main()
{int num;
cout<<"Enter the number: ";
cin>>num;
int result;
result=numofdots(num);
cout<<result;
}
int numofdots(int num)
{   int sum=0;
    while(num!=0)
    {
        sum=sum+num;
        num=num-1;
    }
    return sum;
}








