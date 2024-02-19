#include <iostream>
using namespace std;
bool isIdentityMatrix(int rowSize, int col, int arr[][3]);
void printMatrix(int rowSize, int col, int arr[][3]);
main()
{
    int elements;
    const int col = 3;
    int sum = 0;
    int rowSize = 3;

    int arr[rowSize][col];

    cout << "Enter the elements of the matrix: " << endl;

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter element at position "
                 << "[" << i << "]"
                 << "[" << j << "]"
                 << ": ";
            cin >> arr[i][j];
        }
    }

    printMatrix(rowSize, col, arr);

    if (isIdentityMatrix(rowSize, col, arr))
    {
        cout << "The entered matrix is an identity matrix.";
    }
    else
    {
        cout << "The entered matrix is NOT an identity matrix.";
    }
}

bool isIdentityMatrix(int rowSize, int col, int arr[][3])
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (((i == j) && (arr[i][j] == 1)) || ((i != j) && (arr[i][j] == 0)))
            {
                return false;
            }
        }
    }
    return true;
}

void printMatrix(int rowSize, int col, int arr[][3])
{
    cout<<"The matrix you entered is: "<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
