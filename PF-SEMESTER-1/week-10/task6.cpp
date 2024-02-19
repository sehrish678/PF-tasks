#include<iostream>
#include<cmath>
using namespace std;
int largestnumber(int num,int arr[]);
main()
{
    int num;
    cout<<"Enter the number of elements: ";
    cin>>num;
    int arr[num];
    cout<<"Enter "<<num<<" numbers, one per line: "<<endl;
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    int result;
    result = largestnumber(num,arr);
    cout<<"The largest number entered is: "<<result;

}
int largestnumber(int num,int arr[])
{    float maximum;
    for(int i=0;i<num;i++)
    {
         maximum=max(arr[0],arr[i]);
    }
    return maximum;

}