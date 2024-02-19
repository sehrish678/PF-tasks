#include<iostream>
using namespace std;
void challenge(int speed);
void checkSpeed(int speed);
main() {
	int speed;
	cout<<"Speed: ";
	cin >>speed;
	if(speed > 100)
	{ challenge(speed);
	}
	if(speed <= 100)
	{ checkSpeed(speed);
	} 
	}
	void challenge(int speed)
	{
	 cout <<"Halt... YOU WILL BE CHALLANGED!!!";
	}
	void checkSpeed(int speed)
	{ 
	cout <<"Perfect!You're going good.";
	}