#include<iostream>
using namespace std;
float LowestPrice(float KiloMeters,string Period);
main()
{
    float KiloMeters;
    cout<<"Enter the number of kilometers: ";
    cin>>KiloMeters;
    string Period;
    cout<<"Enter the period of the day (day/night): ";
    cin>>Period;

    float result;
    result=LowestPrice(KiloMeters,Period);
    cout<<"Lowest Price for "<<KiloMeters<<" kilometers: "<<result<<" EUR";
}

float LowestPrice(float KiloMeters,string Period)
{
   
    if(KiloMeters<20 && Period=="night")
    {
        KiloMeters=KiloMeters*0.90;
        KiloMeters=KiloMeters+0.70;
    }
    else if(KiloMeters<20 && Period=="day")
    {
         KiloMeters=KiloMeters*0.79;
        KiloMeters=KiloMeters+0.70;
    }
    else if(KiloMeters>=20 && (Period=="day"||Period=="night"))
    {
        KiloMeters=KiloMeters*0.09;
    }
    else if(KiloMeters>=100 && (Period=="day"||Period=="night"))
    {
        KiloMeters=KiloMeters*0.06;
    }
    return KiloMeters;
}