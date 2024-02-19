#include<iostream>
using namespace std;
main()
{
    #include <iostream>
#include <fstream>
using namespace std;
int countLines(string line);
main()
{
    string line = " ";
    int totalCount = countLines(line);
    cout << "Total number of characters: " << totalCount;

}
int countLines(string line)
{   int sum=0; 
    int count2 = 0;
    fstream data;
    data.open("task3.txt", ios::in);
    while (!data.eof())
    {   count2=0;
        getline(data, line);
        for(int i=0;line[i]!='\0';i++)
      {
        count2++; 
      }
       sum=sum+count2;
    }
    data.close();
    return sum;
}
}
