#include <iostream>
#include "time_f.h"

using namespace std;

int main()
{

    char a=' ';// read the again user input as a charater


    while(a='Y'){//loop if they say yes again

        cout<<endl<<endl;
    //first time
    int hr1;//first time hours
    char colon1;//first time colon
    int min1;//first time min
    char ap1;//first time A,a or P,p

    cout<<"Current Time: ";
    cin>>hr1>>colon1>>min1>>ap1;


    if(valid_std_time(hr1,colon1,min1,ap1)){//check if time is valid

    }
    else{
        return 0;
    }

   //second time

    int hr2;//second time hours
    int min2;//second time min
    char colon2;// second colon

    cout<<"waiting time: ";
    cin>>hr2>>colon2>>min2;

    if(valid_military_time(hr2,colon2,min2)){//check if time is valid

    }
    else{
        return 0;
    }


    int total_min;//time added in mins
    int new_hr;// new hour from the mins added
    char new_ap;//new a or p from the mins added
    int day;// days ahead from the min added(didnt use this for the program) but its needed for time to pass by ref
    int time_diff_;//its the diff of the result time - current time// and its pass by ref for min
    int days;
    int total_mins_from_mil;

  std_time_to_military(hr1,min1,ap1);

  total_mins_from_mil= military_time_to_min(hr2,min2);

 days= only_days_from_mins(total_mins_from_mil);


 total_min= add_military_time(hr1, min1,hr2,min2);

 min_to_day(total_min, day);


 min_to_time(new_hr,total_min,new_ap);

 cout<<"total: ";

 time_display(new_hr,total_min,new_ap);


 cout<<"military_time_diff(new_hr,total_min,hr1,min1)= ";

// time_diff_=time_diff(hr1,min1,ap1,new_hr,total_min,new_ap);

std_time_to_military(new_hr,total_min,new_ap);


time_diff_=military_time_diff(new_hr,total_min,hr1,min1,days);

 int mhr;

 min_to_military_time(mhr,time_diff_);

 military_time_display(mhr,time_diff_);

 cout<<endl;


cout<<endl<<"again? ";//output
cin>>a;//again user input
cout<<endl;

switch(a){  //switch for user input for again

    case 'Y' ://if yes
            break;

    case 'y':
        break;


     case 'N' ://if no get out the program
          cout<<endl;
        return 0;

            break;
    case 'n'://if no get out the program
    cout<<endl;
  return 0;

      break;

    default:// if number is anything other than Y or N than say incorrect input
        cout<<"incorrect input "<<endl;
        return 0;
        break;
}
}


}

