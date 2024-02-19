#include<iostream>
using namespace std;
main()
{   int count;
    int totalprice=0;
    int weight;
    int truck=0;
    int minibus=0;
    int train=0;
    int totalweight=0;
    cout<<"Enter the count of cargo for transportation: ";
    cin>>count;
     
    for(int i=1;i<=count;i++)
    {
        cout<<"Enter the tonnage of cargo "<<i<< " : ";
        cin>>weight;
        totalweight=totalweight+weight;
        
        int minibus=0;
        if(weight<=3)
        {
            totalprice=weight*200;
            minibus=minibus+weight;
        }
        if(weight<=11)
        {
        totalprice=weight*175;
        truck=truck+weight;
        }
        if(weight>11)
        {
            totalprice=weight*120;
            train=train+weight;
        }
    }
     cout<<(totalprice/totalweight)<<"%"<<endl;
     cout<<(minibus/totalweight)*100<<"%"<<endl;
     cout<<(truck/totalweight)*100<<"%"<<endl;
     cout<<(train/totalweight)*100<<"%"<<endl;
}