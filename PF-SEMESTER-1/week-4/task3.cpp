#include<iostream>
using namespace std;
void howManyStickers(int sidelength);
int main() {
	int sidelength;
	cout <<"Enter the side length of the Rubik's Cube: ";
	cin >> sidelength;
	howManyStickers(sidelength);
	}
void howManyStickers(int sidelength)
	{
	int stickers;
	stickers = 6*sidelength*sidelength;
	cout <<"Number of stickers needed: "<<stickers;
	}