#include<iostream>
using namespace std;
void fuel(float distance);
int main() {
	float distance;
	cout <<"Enter the distance: ";
	cin >> distance;
	fuel(distance);
	}
void fuel(float distance)
	{
	int litresoffuel;
	litresoffuel = distance*10;
	cout <<"Fuel needed: "<<litresoffuel;
	}
