#include<iostream>
using namespace std;
void longestduration(int hours,int minutes);
void shortduration(int hours,int minutes);
main() {
	int hours;
	cout<<"Enter the number of hours: ";
	cin >>hours;
	int minutes;
	cout<<"Enter the number of minutes: ";
	cin >>minutes;
	int hourstominutes;
	hourstominutes = hours*60;
	if(hourstominutes > minutes)
	{ 
	longestduration(hours,minutes);
	} 
	if(hourstominutes < minutes)
	{
	shortduration(hours,minutes);
	}
	}
	void longestduration(int hours,int minutes)
	{
	cout <<hours;
	}
	void shortduration(int hours,int minutes)
	{
	cout <<minutes;
	}
	