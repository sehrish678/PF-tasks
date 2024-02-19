#include<iostream>
using namespace std;
string CheckSpeed(float speed);
main()
{
    float speed;
    cout<<"Enter the speed: ";
    cin>>speed;
    string result;
    result=CheckSpeed(speed);
    cout<<result;
}
string CheckSpeed(float speed)
{
    if(speed<=10)
    {
        cout<<"slow";
    }
    else if(speed>10 && speed<=50)
    {
        cout<<"average";
    }
    else if(speed>50 && speed<=150)
    {
        cout<<"fast";
    }
    else if(speed>150)
    {
        cout<<"ultra-fast";
    }
}