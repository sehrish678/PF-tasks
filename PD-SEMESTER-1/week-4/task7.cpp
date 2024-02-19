#include<iostream>
using namespace std;
void total(int redrose,int whiterose,int tulips);

main() {
	int redrose;
	cout<<"Red Rose: ";
	cin >>redrose;
	int whiterose;
	cout<<"White Rose: ";
	cin >>whiterose;
	int tulips;
	cout <<"Tulips: ";
	cin>>tulips;
	total(redrose,whiterose,tulips);
	}
	void total(int redrose,int whiterose,int tulips)
	{
	int allflowers;
	 allflowers = (redrose*2)+(whiterose*4.10)+(tulips*2.50);
	if(allflowers > 200)
	{
	int discount = allflowers-((allflowers*20)/100);
	cout <<"Total price after discount: $"<<discount;
	}
	else{
	cout<<"Original price: $"<<allflowers<<endl;
	cout<<"No discount applied.";
	}
	}
	