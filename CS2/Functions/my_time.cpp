#include "my_time.h"


{
    bool hour(int hr){//fuction to check if hours are valid
        if(hr>12){

                cout<<"Invalid hour"<<endl;


            return false;
        }
        if(hr<0){

        cout<<"Invalid hour"<<endl;


            return false;
        }
        return true;

    }

    bool minutes(int min){//fuction to check if min are valid
        if(min>59){
            cout<<"Invalid minutes"<<endl;

            return false;
        }
        if(min<0){
            cout<<"Invalid minutes"<<endl;

            return false;
        }
        return true;

    }

    bool valid_ampm(char ap){//fuction to check if user didnt put any other charater for a p
        if(ap=='A'){
            return true;
        }
        if(ap=='P'){
            return true;
        }
        else{
            cout<<"Invalid A or P"<<endl;

        return false;
        }

    }

bool ampm(char ap){//fuction to check if its a if not than its p
        if(ap=='A'){

            return true;
        }

        return false;

    }
    int time(int hr, int min){//fuction to convert time to min after 12am
            int overall_time;
            overall_time=hr*60+min;
            return overall_time;

        }



    int time_diff(int time1, int time2){//the difference in min fuction
        int min_diff;
       min_diff =time1-time2;
       return min_diff;


    }

    bool valid_colon(char colon){
        if(colon==':'){
            return true;
        }
        else{
            cout<<"Must use colon for time "<<endl;

             return false;
        }


    }
    char time_display(int hr, int min,char ap){
        display_padded_int(hr);
        cout<<":";
        display_padded_int(min);
        cout<<ap<<"M";

    }

    int display_padded_int(int number){
        if(number<10){
            cout<<"0"<<number;
        }
        else{
            cout<<number;
        }
    }
    int time_after_12(int hr, int min){//fuction to convert time to min after 12am
            int overall_time;
            overall_time=(hr+12)*60+min;
            return overall_time;

        }
    int time_add(int hr1,int min1, char ap1,int hr2, int min2, char ap2){
        int add;
        if(ampm(ap1)){
            if(ampm(ap2)){
            add=time(hr1,min1)+time(hr2,min2);
            }
            else{
                add=time(hr1,min1)+time_after_12(hr2,min2);
            }

        }
        else{
            if(ampm(ap2)){
            add=time_after_12(hr,min)+time(hr2,min2);
            }
            else{
               add=time_after_12(hr1,min1)+time_after_12(hr2,min2);
            }
        }
        return add;


    }
 bool valid_time(int hr, char colon, int min, char ap){
        if(hour(hr)){
            if(valid_colon(colon)){
                if(minutes(min)){
                    if(valid_ampm(ap)){
                       return true;
                    }
                }

            }
        }

        return false;

    }
 int min_to_hr(n){
     int hr;
     hr=n/60;
     return hr;
 }
 int min_of_hr(n){
     int min;
     min=n%60;

 }
 char ampm_con(hr,min){
     int total_hr;
     if(hr>12){
         total_hr=hr-12;

     }
     else{
         total_hr=hr;

     }
 }


}
