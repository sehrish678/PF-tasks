#include<iostream>
using namespace std;
main()
{   int sum =0;
    int sum2 =0;
    int doctors =7;
    int untreated=0;
    int treated =0;
    int patientcount =0;
    cout<<"Enter Number of days you visited Hospital: ";
    cin>>patientcount;
    for(int day=1;day <=patientcount;day=day+1)
    {
    cout<<"Number of patients visited hospital on Day ";
    
    for(int i=day;i<=day;i++)
    {
        cout<<i<<": ";
        int patient;
        cin>>patient;
    if( patient <=doctors)
    {
        
        treated = doctors+treated;
    }
    if(patient > doctors)
    {
         untreated = patient - treated;
         treated = doctors;
    }
     sum = untreated +sum;
    sum2 = treated +sum2;
     
    if((day%3 ==0 )&& (sum > sum2))
    { 
         treated = treated +1;
    }

   
}

}
cout<<"Treated Patients: "<<sum2<<endl;
cout<<"Untreated Patients: "<<sum<<endl;

}


