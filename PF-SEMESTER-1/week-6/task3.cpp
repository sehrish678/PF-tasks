#include<iostream>
using namespace std;
main()
{
    string letter;
    cout<<"Enter the shape (s for square, c for circle , t for triangle , h for hexagon): ";
    cin>>letter;
    float value;
    cout<<"Enter the value: ";
    cin>>value;
    float perimeter;
    if(letter=="c")
    {
        perimeter=6.28*value;
    }
    else if(letter=="s")
    {
         perimeter=4*value;
    }
     else if(letter=="t")
    {
         perimeter=3*value;
    }
     else if(letter=="h")
    {
         perimeter=6*value;
    }
    cout<<"The perimeter is: "<<perimeter;
}