#include<iostream>
using namespace std;
void triangle1(int num1);
void triangle2(int num1);
main()
{int num1;
cout<<"Enter the number: ";
cin>>num1;
triangle1(num1);
triangle2(num1);
}
void triangle1(int num1)
{   int num=num1/2;
    for(int i=1;i<=num;i++)
    {
        for(int k=1;k<=num-i;k++)
        cout<<" ";
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
      
}
void triangle2(int num1)
{int num=num1/2;
for(int i=1;i<=num;i++)
{
    for(int k=1;k<i;k++)
    cout<<" ";
    for(int j=i;j<=num;j++)
    {
        cout<<"*";
    }
    cout<<endl;
    }
    
}