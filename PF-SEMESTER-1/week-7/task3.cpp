#include<iostream>
using namespace std;
int totalnumOfDigits(int num);
main()
{
    int num;
    cout << "Enter a num: ";
    cin >> num;
    int output;
    output = totalnumOfDigits(num);
    cout << "Total num of digits: " << output;
}

   int totalnumOfDigits(int num){
      int count=0;
      while(num > 0){
        int remiander ;
        remiander = num%10;
        num = num/10;
        count++;
      }
      return count;
      }
      
   














