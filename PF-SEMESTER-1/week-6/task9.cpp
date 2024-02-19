#include<iostream>
using namespace std;
main()
{
    int age;
    cout<<"Enter your age: ";
    cin>>age;
    string gender;
    cout<<"Enter your gender (m/f): ";
    cin>>gender;
    string title;
    if(gender=="m"&& age>=16)
    {
        title="Mr.";
    }
    else if(gender=="f"&& age<16)
    {
        title="Miss";
    }
    else if(gender=="m"&& age<16)
    {
        title="Master";
    }
    else if(gender=="f" && age>=16)
    {
        title="Ms.";
    }
    cout<<"Your personal title is: "<<title;
}