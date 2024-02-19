#include<iostream>
using namespace std;
main() {
	cout <<"Enter the Name of the Person: ";
	string name;
	cin>> name;
	cout <<"Enter the target weight loss in kilograms: ";
	float kgs;
	cin>> kgs;
	float wl;
	wl = kgs*15;
	cout <<name;
	cout <<" will need ";
	cout <<wl;  
	cout <<" days";
	cout <<" to lose ";
	cout <<kgs; 
	cout <<" kg";
	cout <<" of weight by following the doctor's suggestions";
	}