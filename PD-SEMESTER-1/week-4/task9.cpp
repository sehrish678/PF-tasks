#include<iostream>
using namespace std;
void tpchecker(int holidays,int rolls);
main() {
	int people;
	cout<<"Number of people in the household: ";
	cin >>people;
	int rolls;
	cout<<"Number of rolls of TP: ";
	cin >>rolls;
	tpchecker(people,rolls);
	}
	void tpchecker(int people,int rolls)
	{
	int totaltissue;
	totaltissue = people*57;
	int daysleft;
	daysleft = (rolls*500)/people;
	if(daysleft >= 14)
	{
	cout<<"Your TP will last "<<daysleft<<" days, no need to panic!";
	}
	if(daysleft < 14)
	{
	cout<<"Your TP will only "<<daysleft<< " days, buy more!";
	} 
	}