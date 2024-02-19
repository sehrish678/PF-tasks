#include<iostream>
using namespace std;
int isEvilNumber(int num,int count);
bool isPrime(int count);
main()
{    int count=0;
    int num;
    cout<<"Enter the number: ";
    cin>>num;
 
 if(isEvilNumber(num,count))
 {
    cout<<"Evil number.";
 }
 
 if((count<2)||(count%2)!=0)
 {
    cout<<"Pernicious number.";
 }
 if((count%2)!=0)
 {
    cout<<"Odious number.";
 }

}
int isEvilNumber(int num,int count)
{
   
    while(num!=0)
    {
        int mode=num%2;
        if(mode==1)
        count++;
        num=num/2;
    }
    if(count%2==0)
    {   
        return 1;
    }
    else{
        return 0;
    }
}


