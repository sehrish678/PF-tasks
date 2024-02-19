#include<iostream>
using namespace std;
void feet(float inches);
int main() {
	float inches;
	cout <<"Enter the measurement in inches: ";
	cin >> inches;
	feet(inches);
	}
void feet(float inches)
	{
	float feet;
	feet = inches/12;
	cout <<"Equivalent in feet: "<<feet;
	}