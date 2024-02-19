#include<iostream>
using namespace std;
main() {
	cout <<"Enter the movie name: ";
	string name;
	cin>> name;
	cout <<"Enter the adult ticket price: $";
	float ap;
	cin>> ap;
	cout <<"Enter the child ticket price: $";
	float cp;
	cin>> cp;  
	cout <<"Enter the number of adult tickets sold: " ;
	float ats;
	cin>> ats;
	cout <<"Enter the number of child tickets sold: ";
	float cts;
	cin>> cts; 
	cout <<"Enter the percentage of the amount to be donated to charity: ";
	float per;
	cin>> per;
	cout << endl;
	cout <<"Movie: " <<name<<endl;
	float sale;
	sale = (ap*ats)+(cp*cts);
	cout <<"Total amount generated from ticket sales: $"<<sale<<endl;
	float cha;
	cha = sale/per;
	cout <<"Donation to charity (10%): $"<<cha<<endl; 
	float am;
	am = sale-cha;
	cout <<"Remaining amount after donation: $" <<am<<endl;
       }