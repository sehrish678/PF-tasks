#include<iostream>
using namespace std;
void reverse(int num1,int arr[]);
main()
{
int num1,num2;
cout<<"Enter the number of elements: ";
cin>>num1;
if(num1<=0)
{
    cout<<"Invalid input. Number of elements must be greater than 0."<<endl;
    return 0;
}
int arr[num1];
cout<<"Enter "<<num1<<" numbers"<<" , one per line: "<<endl;
for(int x=1;x<=num1;x++)
{
    cin>>arr[x];
    }
    cout<<"Numbers in reverse order: ";
    reverse(num1,arr);
    }
void reverse(int num1,int arr[])
{

for(int i=num1;i>0;i--){

    cout<<arr[i]<<" ";
}

}
