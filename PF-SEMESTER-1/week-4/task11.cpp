#include<iostream>
using namespace std;
void myname(string name);
 main() {
	string name;
	cout <<"Enter your name: ";
	cin >>name;
	while(true)
	{
	myname(name);
	;
	}
	}
	void myname(string name)
	{
	cout <<name;
	}