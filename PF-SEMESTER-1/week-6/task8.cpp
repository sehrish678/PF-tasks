#include<iostream>
using namespace std;
main()
{
    
    string Day;
    cout<<"Enter Purchase day: ";
    cin>>Day;
    string Month;
    cout<<"Enter Purchase Month: ";
    cin>>Month;
    float amount;
    cout<<"Enter the Purchase Amount: ";
    cin>>amount;
    float discount;

    if( Day=="Sunday"&& (Month=="October")||(Month=="March")||(Month=="August"))
    {
        discount=amount-((amount*10)/100);
    }
    else if(Day=="Monday"&& (Month=="November")||(Month=="December"))
    {
        discount=amount-((amount*5)/100);
    }
    else {
        discount=amount;
    }
    cout<<"Payable Amount after discount: "<<discount;

}