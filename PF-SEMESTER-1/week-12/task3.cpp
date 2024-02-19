#include <iostream>
using namespace std;
main()
{   int elements;
    const int col = 3;
    int sum = 0;
    int rowSize;
    cout << "Enter row size: ";
    cin >> rowSize;

    cout << "Enter the elements of the matrix: "<<endl;
    
   

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter element at position "
                 << "[" << i << "]"
                 << "[" << j << "]"
                 << ": ";
            cin >> elements;
             sum = sum + elements;
        }
    }
 cout<<"The sum of elements in the matrix is: "<<sum<<endl;
}

