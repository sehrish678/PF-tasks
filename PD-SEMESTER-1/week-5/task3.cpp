#include<iostream>
using namespace std;
char type;
float price;
float taxcalculator(char type,float price);

float taxcalculator1(char type,float price);
float taxcalculator2(char type,float price);
float taxcalculator3(char type,float price);
float taxcalculator4(char type,float price);
main ()
{
    char type;
    float price;
    cout <<"Enter the vehicle type code (M, E, S, V, T): ";
    cin >> type;
    cout <<"Enter the price of the vehicle: $";
    cin >> price;
    taxcalculator( type, price);
    taxcalculator1(type,price);
    taxcalculator2(type, price);
    taxcalculator3(type, price);
    taxcalculator4(type,price);
    return 0;

}
float taxcalculator(char type,float price)
{
    float taxM;
    taxM = (price*6)/100;
    float taxamountM;
    taxamountM = price+taxM;
    if(type == 'M')
    {
        cout <<"The final price of the vehicle of type "<<type<<" after adding the tax is "<<"$"<<taxamountM<<endl;
    }
}
float taxcalculator1(char type,float price)
 {   
    float taxE;
    taxE = (price*8)/100;
    float taxamountE;
    taxamountE = price+taxE;
    if(type == 'E')
    {
        cout <<"The final price of the vehicle of type "<<type<<" after adding the tax is "<<"$"<<taxamountE<<endl;
    }
 }
float taxcalculator2(char type,float price)
{
    float taxS;
    taxS = (price*10)/100;
    float taxamountS;
    taxamountS = price+taxS;
    if(type == 'S')
    {
        cout <<"The final price of the vehicle of type "<<type<<" after adding the tax is "<<"$"<<taxamountS<<endl;

    }
    }
float taxcalculator3(char type,float price)
   {float taxV;
    taxV = (price*12)/100;
    float taxamountV;
    taxamountV = price+taxV;
    if(type == 'V')
    {
     cout <<"The final price of the vehicle of type "<<type<<" after adding the tax is "<<"$"<<taxamountV<<endl;   
    }    
    }
float taxcalculator4(char type,float price)
   {
    float taxT;
    taxT = (price*15)/100;
    float taxamountT = price+taxT;
    if(type == 'T')
    {

    
     cout <<"The final price of the vehicle of type "<<type<<" after adding the tax is "<<"$"<<taxamountT<<endl; 
    }    
return 0;
    }


    