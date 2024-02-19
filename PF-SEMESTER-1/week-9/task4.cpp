#include<iostream>
using namespace std;
void ReverseNumber(int array[], int num){
    for(int x = num-1; x>=0; x--){
        cout << array[x] << " ";
    }
    cout << endl;
}
int main(){
    int num;
    cout << "Enter the num of elements: ";
    cin >> num;
    if(num <= 0){
        cout << "Invalid input. Number of elemets must be greater than 0."<<endl;
        return 0;
    }
    int array[num];
    cout << "Enter "<< num << "numbers, one per line: " << endl;
    for(int x=0; x < num; x++){

    cin >> array[x];

    }
    cout << "Numbers in reverse order: ";
    ReverseNumber(array, num);
    return 0;
}