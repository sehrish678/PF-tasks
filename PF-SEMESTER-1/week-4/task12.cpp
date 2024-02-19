#include<iostream>
using namespace std;
void purchase(int amount);
void purchaseotherday(int amount);
main() {
	string day;
	cout <<"Enter the day of purchase: ";
	cin >>day;
	int amount;
	cout <<"Enter the total purchase amount: ";
	cin >>amount;
	if(day == "Sunday")
	{
	purchase(amount);
	}
	if(day!= "Sunday")
	{ 
	purchaseotherday(amount);
	}
	}
	void purchase(int amount)
	{ int discount;
	discount = amount-((amount*10)/100);
	cout <<"Payable amount: "<<discount;
	}
	void purchaseotherday(int amount)
	{ int disc;
	disc = amount-((amount*5)/100);
	cout <<"Payable amount: "<<disc;
	}