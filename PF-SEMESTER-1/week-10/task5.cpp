#include<iostream>
using namespace std;
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
        if(arr[0]==arr[i])
        {
            cout<<"Already Entered: "<<arr[i];
            arr[i]++;
        }
    }
}
