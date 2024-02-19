#include<iostream>
using namespace std;
main() {
	cout <<"Enter Imposter Count: ";
	float ic;
	cin>> ic;
	cout <<"Enter Player Count: ";
	float pc;
	cin>> pc;
	float im;
	im = 100*(ic/pc);
	cout <<"Chance of being an imposter: ";
	cout <<im;
	cout <<"%";
	}