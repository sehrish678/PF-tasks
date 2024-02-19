#include<iostream>
using namespace std;
string CheckBudget(float budget,string Category,int NumOfPeople);
main()
{
    float budget;
    cout<<"Enter the budget: ";
    cin>>budget;
    string Category;
    cout<<"Enter the category (VIP/Normal): ";
    cin>>Category;
    int NumOfPeople;
    cout<<"Enter the number of people: ";
    cin>>NumOfPeople;

    CheckBudget(budget,Category,NumOfPeople);
   

}

string CheckBudget(float budget,string Category,int NumOfPeople)
{   float TicketPrice;
    float finalTicketPrice;
    
    if(NumOfPeople >=1 && NumOfPeople <= 4)
    {
        budget=budget-(budget*0.75);
    }
    if(NumOfPeople >=5 && NumOfPeople <= 9)
    {
        budget=budget-(budget*0.60);
    }
    if(NumOfPeople >=10 && NumOfPeople <= 24)
    {
        budget=budget-(budget*0.50);
    }
    if(NumOfPeople >=25 && NumOfPeople <= 49)
    {
        budget=budget-(budget*0.40);
    }
    

    if(Category=="Normal")
    {
        TicketPrice=249.99*NumOfPeople;
    }
    else if(Category=="VIP")
    {
        TicketPrice=499.99*NumOfPeople;
    }

    finalTicketPrice=(budget-TicketPrice)+0.000005;

    if(finalTicketPrice > 0)
    {
        cout<<"Yes! You have "<<to_string(finalTicketPrice)<<" leva left.";
    }
    else
    {
        cout<<"Not enough money! You need "<<to_string(finalTicketPrice)<<" leva.";
    }
}