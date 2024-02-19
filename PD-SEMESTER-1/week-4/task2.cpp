#include<iostream>
using namespace std;
void condition1(string name);
void condition2(string name);
main() {
	string name;
	cout<< "Enter 'true' or 'false': ";
	cin >>name;
	
	if(name == "true" )
	{
	condition1(name);
	}
	if(name!= "true")
	{
	condition2(name);
	}
	}
	void condition1(string name)
	{
	cout <<"false";
	}
	void condition2(string name)
	{
	cout <<"true";
	}