#include<iostream>
using namespace std;
float EvenOROdd(int num);  
main()
{
    int num;
    cout<<"Enter the five-digit number: ";
    cin>>num;
    EvenOROdd(num);  
    }
float EvenOROdd(int num)    
    {
    int sum=0;
    while((num)!=0)
    {
        int mode;
        mode=num%10;
        num=num/10;
        sum=sum+mode;
        
    }
    if((sum%2)==0)
    {
        cout<<"Evenish";
    }   
    else if((sum%2)!=0)
    {
        cout<<"Oddish";
    } 
}
