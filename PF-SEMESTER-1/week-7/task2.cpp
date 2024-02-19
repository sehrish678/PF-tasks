#include<iostream>
using namespace std;



void FibbonacciSeries(int length) {
    int num1 = 0;
    int num2 = 1;  
    int next;

    for (int i = 0; i < length; i++) {
        cout << num1;
      
        if(i!=length-1){
        cout << ", ";
        }
        next = num1 + num2;
        num1 = num2;
        num2 = next;
    }
    cout << endl;
}






