#include<iostream>
using namespace std;
void asterik(int num);
main()
{int num;
cout<<"Enter the number: ";
cin>>num;
asterik(num);
}
void asterik(int num)
{
    for(int i=num;i>=1;i--)
    {
        for(int j=i;j>=1;j--)
        {
            cout<<"*";

        }
        cout<<endl;
    }
}