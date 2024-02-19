#include<iostream>
using namespace std;
float heightoftree(float base,float angle);
main()
{
    float base;
    cout<<"Enter the distance from the tree (in feet): ";
    cin>>base;
    float angle;
    cout<<"Enter the angle of elevation (in degrees): ";
    cin>>angle;
    float result;
    result=heightoftree(base,angle);
    cout<<"The height of the tree is: "<<result<<" feet";
}
float heightoftree(float base,float angle)
{
    float radian;
    radian=(angle/57.2958);
    float height;
    height = radian * base;
    return height;
}