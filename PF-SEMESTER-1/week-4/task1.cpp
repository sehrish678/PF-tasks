#include<iostream>
using namespace std;
void calculatefuel(float distance);
int main() {
	float distance;
	cout <<"Enter the distance: ";
	cin >> distance;
	calculatefuel(distance);
	}
void calculatefuel(float distance)
	{
	float fuel;
	fuel = distance*10;
	cout <<"Fuel needed: "<<fuel;
	}