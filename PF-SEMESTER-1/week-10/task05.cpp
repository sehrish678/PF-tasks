#include<iostream>
using namespace std;
main()
{
int num1;
cout<<"Enter the number of elements: ";
cin>>num1;
int arr[100];
cout<<"Enter "<<num1<<" numbers"<<" , one per line: "<<endl;

for(int j=1;j<=num1;j++)
{
    cin>>arr[j];
   
  
        if(arr[j]==arr[j-1])
        {
            cout<<"Already Entered: "<<arr[j];
          
        }
        else{
            arr[j]++;
        }

}
}