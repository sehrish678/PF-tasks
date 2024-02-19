#include<iostream>
using namespace std;
void number(int num1,int num2);
void num(int num1,int num2);
main() {
	int num1;
	cout<< "Enter the first number: ";
	cin >>num1;
	int num2;
	cout <<"Enter the second number: ";
	cin >> num2;
	if(num1 == num2 )
	{
	number(num1,num2);
	}
	if(num1!=num2)
	{
	num(num1,num2);
	}
	}
	void number(int num1,int num2)
	{
	cout <<"true";
	}
	void num(int num1,int num2)
	{
	cout <<"false";
	}