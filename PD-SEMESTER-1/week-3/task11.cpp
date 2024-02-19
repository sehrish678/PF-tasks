#include<iostream>
using namespace std;
main() {
	cout <<"Enter the person's age: ";
	int age;
	cin>> age;
	cout <<"Enter the number of times they've moved: ";
	int mov;
	cin>> mov;
	int avg;
	avg = age/(mov+1);
	cout <<"Average number of years lived in the same house: " <<avg;
	}