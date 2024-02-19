#include<iostream>
using namespace std;
float Totalincome(string ScrType,int rows,int columns);
main()
{
    string ScrType;
    cout<<"Enter the screening type (Premiere/Normal/Discount): ";
    cin>>ScrType;
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    int columns;
    cout<<"Enter the number of coloumns: ";
    cin>>columns;
float result=Totalincome(ScrType,rows,columns);
cout<<result;

}
float Totalincome(string ScrType,int rows,int columns)
{   float total;
    if(ScrType=="Premiere")
    {
        total=12*rows*columns;
    }
    else if(ScrType=="Normal")
    {
        total=7.50*rows*columns;
    }
    else if(ScrType=="Discount")
    {
        total=5.00*rows*columns;
    }
    return total;
}