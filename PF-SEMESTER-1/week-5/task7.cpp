#include<iostream>
using namespace std;
float symmetrical(int num);
main()
{
    int num;
    cout<<"Enter a three-digit number: ";
    cin>>num;
    symmetrical(num);
}

float symmetrical(int num)
{
    int mode=num%10;
    int div1=num/10;
    int mode2=div1%10;
    int div2=div1/10;
    int mode3=div2%10;
    int div3=div2/10;

    
    if((mode==mode2)||(mode==mode3)||(mode3==mode2))
    {
        cout<<"The number is symmetrical."; 
    }
    else{
        cout<<"The number is not symmetrical.";
    }
}