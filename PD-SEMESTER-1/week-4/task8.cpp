#include<iostream>
using namespace std;
void pet(int holidays);
main() {
	int holiday;
	cout<<"Holidays: ";
	cin >>holiday;
	pet(holiday);
	}
	void pet(int holiday)
	{
	int workingdays;
	workingdays = 365-holiday;
	int timetoplay;
	timetoplay = (workingdays*63+holiday*127);
	int difference;
	difference = 30000-timetoplay;
	int hours;
	hours = difference/60;
	int minutes;
	minutes = (difference%60);
	if(timetoplay <= 30000)
	{cout<<"Tom sleeps well"<<endl;
	cout<<hours << " hours and " <<minutes <<" minutes less for play"; 
	}
	if(timetoplay > 30000)
	{cout<<"Tom will run away" <<endl; 
	cout<< -1*hours <<" hours and " << -1*minutes << " minutes for play";
	}
	}
	 
	