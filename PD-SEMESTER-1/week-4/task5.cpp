#include<iostream>
using namespace std;
void myposition(int position1,int position2);
void myfriendsposition(int position1,int position2);
main() {
	int position1;
	cout<<"Enter your position: ";
	cin >>position1;
	int position2;
	cout<<"Enter your friend's position: ";
	cin >>position2;
	int op;
	op = position2-position1;
	
	if(op <= 6)
	{ 
	myposition(position1,position2);
	}
	if(op > 6)
	{ 
	myfriendsposition(position1,position2);
	}
	}
	void myposition(int position1,int position2)
	{ 
	cout<<"true" ;
	}
	void myfriendsposition(int position1,int position2)
	{ 
	cout<<"false" ;
	}	