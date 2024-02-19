#include<iostream>
using namespace std;
void vote(int age);
void novote(int age);
main() { 
	int age;
	cout <<"Enter your age: ";
	cin >>age;
	if(age >= 18)
	{ vote(age);
	} 
	if(age <= 17)
	{
	novote(age);
	}
	}
	void vote(int age)
	{
	cout <<"You are eligible to vote.";
	}
	void novote(int age)
	{
	cout <<"You are not eligible to vote.";
	}
