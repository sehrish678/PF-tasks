 #include<iostream>
using namespace std;
float projectimecalculation(int hoursneeded,int days,int numofworkers);
main() {
    int hoursneeded,days,numofworkers;
    cout <<"Enter the needed hours: ";
    cin >> hoursneeded;
    cout <<"Enter the days that the firm has: ";
    cin >> days;
    cout <<"Enter the number of all workers: ";
    cin >> numofworkers;
  projectimecalculation(hoursneeded,days,numofworkers);
 
}
float projectimecalculation(int hoursneeded,int days,int numofworkers)
{ 
    float time;
    time = (days*0.1);
    float subtract;
    subtract = days-time;
    float workingdays;
    workingdays = subtract*10*numofworkers;
    int remaininghours;
    
     if(workingdays < hoursneeded)
    {remaininghours = hoursneeded-workingdays;
        cout <<"Not enough time! "<<remaininghours<<" hours needed "; 
    }
    if(workingdays >= hoursneeded)
    {
    remaininghours = workingdays-hoursneeded;
        cout <<"Yes! "<<remaininghours<<" hours left.";
    }
    return 0;
    }
    