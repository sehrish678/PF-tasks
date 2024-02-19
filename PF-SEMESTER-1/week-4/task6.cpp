#include<iostream>
using namespace std;
void pass(int num);
void fail(int num);
main() { 
	int num;
	cout <<"Enter your score: ";
	cin >>num;
	if(num > 50)
	{ pass(num);
	} 
	if(num <= 50)
	{
	fail(num);
	}
	}
	void pass(int num)
	{
	cout <<"Pass";
	}
	void fail(int num)
	{
	cout <<"Fail";
	}
