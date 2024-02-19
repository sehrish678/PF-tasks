#include<iostream>
using namespace std;
main() {
	cout <<"Enter Initial Velocity (m/s): ";
	float vel;
	cin>> vel;
	cout <<"Enter Acceleration (m/s^2): ";
	float acc;
	cin>> acc;
	cout <<"Enter Time (s): ";
	float time;
	cin>> time;
	float fv;
	fv = acc*time+vel;
	cout <<"Final Velocity (m/s): ";
	cout <<fv;
	}