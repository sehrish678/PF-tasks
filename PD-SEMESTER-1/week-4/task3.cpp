#include<iostream>
using namespace std;
void country1(string name,float amount);
void country2(string name,float amount);
void country3(string name,float amount);
void country4(string name,float amount);
void country5(string name,float amount);
main() {
	string name;
	cout<<"Enter the country's name: ";
	cin >>name;
	int amount;
	cout<<"Enter the ticket price in dollars: $";
	cin >>amount;
	if(name == "Pakistan")
	{
	country1(name,amount);
	}
	if(name == "Ireland")
	{
	country2(name,amount);
	}
	if(name == "India")
	{ country3(name,amount);
	}
	if(name == "England")
	{ country4(name,amount);
	}
	if(name == "Canada")
	{ country5(name,amount);
	}
	}
	void country1(string name,float amount)
	{ float disc1;
	disc1 = amount-((amount*5)/100);
	cout <<"Final ticket price after discount: $"<<disc1;
	}
	void country2(string name,float amount)
	{float disc2;
        disc2 = amount-((amount*10)/100);
	cout <<"Final ticket price after discount: $"<<disc2;
	}
	void country3(string name,float amount)
	{float disc3;
	disc3 = amount-((amount*20)/100);
	cout <<"Final ticket price after discount: $"<<disc3;
	}
	void country4(string name,float amount)
	{ float disc4;
	disc4 = amount-((amount*30)/100);
	cout <<"Final ticket price after discount: $"<<disc4;
	}
	void country5(string name,float amount)
	{float disc5;
	disc5 = amount-((amount*45)/100);
	cout <<"Final ticket price after discount: $"<<disc5;
	}