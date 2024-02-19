#include<iostream>
using namespace std;
main()
{

    int num;
    cout<<"Enter number of elements: ";
    cin>>num;
    int arr[num];
    cout<<"Enter numbers: "<<endl;
    for(int i=0;i<num;i++)
    {   cin>>arr[i];
       if(arr[num]==arr[num+1])
     
        {
            cout<<"Already Entered: "<<arr[num];
        }
  
    }
     
}