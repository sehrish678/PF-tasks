#include<iostream>
using namespace std;
main() {
	cout <<"Enter the size of the fertilizer bag in pounds: ";
	int pounds;
	cin>> pounds;
	int total;
	cout <<"Enter the cost of the bag: $";
	int cost;
	cin>> cost;
	cout <<"Enter the area in square feet that can be covered by the bag: ";
	int sqf;
	cin>> sqf;
	int pp;
	pp = cost/pounds;
	cout <<"Cost of fertilizer per pound: $"<<pp<<endl;
	int ps;
	ps = cost/sqf;
	cout <<"Cost of fertilizing per square foot: $"<<ps;
	
	}