#include<iostream>
using namespace std;
main() {
	cout <<"Enter vegetable price per kilogram (in coins): ";
	float veg;
	cin>> veg;
	cout <<"Enter fruit price per kilogram (in coins): ";
	float fruit;
	cin>> fruit;
	cout <<"Enter total kilograms of vegetables: ";
	float kv;
	cin>> kv;  
	cout <<"Enter total kilograms of fruits: " ;
	float kf;
	cin>> kf;
	float total; 
	total = (veg*kv+fruit*kf)/1.94;
	cout <<"Total earnings in Rupees (Rps): ";
	cout <<total;
	}