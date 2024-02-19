#include<iostream>
using namespace std;
void discount(int amount);
void purchase(int amount);
	
main() { 
	string day;
	cout <<"Enter the day of purchase: ";
	cin >>day;
	int amount;
	cout <<"Enter the total purchase amount: $";
	cin >>amount;
	if(day == "Sunday")
	{ purchase(amount);
	} 
	if(day!= "Sunday")
	{ discount(amount);
	}
	}
	void purchase(int amount)
	{int disc;
	disc = amount-((amount*10)/100);
	cout <<"Payable amount: $"<<disc;
	}
	void discount(int amount)
	{
	cout <<"Payable Amount: $"<<amount;
	}
