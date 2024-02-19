#include<iostream>
using namespace std;
string ASCII(string name);
main()
{
    string name;
    cout<<"Enter a string: ";
    getline(cin,name);
    ASCII(name);
}
string ASCII(string name)
{   char character2;
   cout<<"Shifted String: "; 
    for(int x=0;name[x]!='\0';x++)
    {   if(name[x]=='Z')
    {
        cout<<"A";
    }
    else if(name[x]==' ' )
    {
       cout<< name[x];
    }else{
        char character=name[x];
        int asciiCode=character;
        asciiCode++;
        character2=asciiCode;
        cout<<character2;
        }
    }
    
     
}
