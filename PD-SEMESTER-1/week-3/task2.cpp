#include<iostream>
using namespace std;
main() {
	cout <<"Number of Minutes: ";
	int min;
	cin>> min;
	cout <<"Frames per Second: ";
	int sec;
	cin>> sec;
	int total;
	total = min * sec * 60;
	cout <<"Total Number of Frames: ";
	cout <<total;
	}
