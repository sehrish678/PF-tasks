#include<iostream>
#include<windows.h>
using namespace std;

	void gotoxy(int x, int y)
	{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
	}

	int main()
	{
	system("cls");
	cout<< "Test";

	gotoxy(55,15);
	
	cout<< "H"<<endl;
	gotoxy(55,16);
	cout<< "A"<<endl;
	gotoxy(55,17);
	cout<< "S"<<endl;
	gotoxy(55,18);
	cout<< "S"<<endl;
	gotoxy(55,19);
	cout<< "A"<<endl;
	gotoxy(55,20);
	cout<< "N"<<endl;
	
	return 0;
	}