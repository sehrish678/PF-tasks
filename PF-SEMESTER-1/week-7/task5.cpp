#include<iostream>
using namespace std;
int SumOfDigits(int num);
main()
{
    int num;
    cout << "Enter a num: ";
    cin >> num;
    int result;
    result = SumOfDigits(num);
    cout << "Sum of digits: " << result;
}

   int SumOfDigits(int num){
      int sum=0;
      while(num > 0){
        int remiander ;
        remiander = num%10;
        num = num/10;
        sum = sum+remiander;
      }
      return sum;;
      }
      