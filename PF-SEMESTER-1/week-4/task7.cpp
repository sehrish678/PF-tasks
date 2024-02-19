#include<iostream>
using namespace std;
void even(int num);
void odd(int num);
main() { 
	int num;
	cout <<"Enter a number: ";
	cin >>num;
	if(num%2 == 0)
	{ even(num);
	} 
	if(num%2 == 1)
	{ odd(num);
	}
	}
	void even(int num)
	{
	cout <<"Number "<<num<<" is even";
	}
	void odd(int num)
	{
	cout <<"Number "<<num<<" is odd";
	}
