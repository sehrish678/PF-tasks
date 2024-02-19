#include<iostream>
using namespace std;
main()
{
    string letter;
    cout<<"Enter a character (A/a): ";
    cin>>letter;
    if(letter=="a")
    {
        cout<<"You have entered small "<<letter;
    }
    if(letter=="A")
    {
        cout<<"You have entered Capital "<<letter;
    }
}