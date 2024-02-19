#include<iostream>
using namespace std;
main() {
	cout <<"Enter the number of sides of the polygon: ";
	float sides;
	cin>> sides;
	float angle;
	angle = (sides-2)*180;
	cout <<"The sum of internal angles of a ";
	cout <<sides;
    cout << "-sided polygon is: ";
	cout <<angle <<" degrees";
}
	
	