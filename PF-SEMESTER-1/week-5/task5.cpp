#include<iostream>
#include<cmath>
using namespace std;
float solution(int a,int b,int c);
main()
{
    int a,b,c;
    cout<<"Enter the value of a: ";
    cin>>a;
    cout<<"Enter the value of b: ";
    cin>>b;
    cout<<"Enter the value of c: ";
    cin>>c;
    solution(a,b,c);
}
float solution(int a,int b,int c)
{
  float determinant;
  determinant=((b*b)-(4*a*c));
  if(determinant>0)
  {  
    int root1,root2;
    root1=(-b+(sqrt(determinant))/(2*a));
    root2=(-b+(sqrt(determinant))/(2*a));
    cout<<"Solutions: "<<"x= "<<root1<<"x= "<<root2<<endl;
  }  
  else if(determinant<0)
  {
    int root1,root2;
    root1=(-b/(2*a))+(sqrt(determinant)/(2*a));
    root2=(-b/(2*a))-(sqrt(determinant)/(2*a));
    cout<<"Complex Solutions: "<<"x= "<<root1<<"x= "<<root2<<endl;
  }
  else{
    int root1,root2;
    root1=(-b/(2*a));
    root1=root2;
    cout<<"Solutions: "<<"x= "<<root2<<endl;

  }
  return 0;
}