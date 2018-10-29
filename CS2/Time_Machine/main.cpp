#include <iostream>

using namespace std;

int time(int hr, int min);//fuction to convert time to min after 12am
bool valid_ampm(char ap);//fuction to check if user didnt put any other charater for a p
bool ampm(char ap);//fuction to check if its a if not than its p
int time_diff(int time1, int time2);//the difference in min fuction
bool hour(int hr);//fuction to check if hours are valid
bool minutes(int min);//fuction to check if min are valid
bool valid_colon(char colon);
char time_display(int hr, int min, char ap);
int display_padded_int(int number);
int Abs(int diff_min);

int main()
{
    cout<<endl<<endl<<"--------------------------------"<<endl;
    char colon1;
    int hr1;//starting time hour
    int min1;//starting time min
    char ap1;// starting time a or p
    int time1;// the conversion of starting time to mins


    char colon2;
    int hr2;//future time hour
    int min2;//fututre time min
    char ap2;//future time a or p
    int time2;// the conversion of future time to mins
    int Abs_diff_min;//to make the difference is always postive


    int diff_min;//the diff of time between starting and future time;

    cout<<"Starting time: "<<endl;
    cin>>hr1>>colon1>>min1>>ap1;

   if(hour(hr1)){//if valid hour

        if(valid_colon(colon1)){//if its colon

        if(minutes(min1)){// if min is valid

            if(valid_ampm(ap1)){// if ap is a or p

            if(ampm(ap1)){//separate (am)


                time1=time(hr1,min1);

            }
            else{//separate (pm)

                time1=time(hr1+12,min1);


            }

        }

        }

        }

    }
   else{
       return 0;
   }


    cout<<"Future time: "<<endl;
    cin>>hr2>>colon2>>min2>>ap2;

    if(hour(hr2)){//if valid hour

        if(valid_colon(colon2)){//if its colon

        if(minutes(min2)){// if min is valid

            if(valid_ampm(ap2)){// if ap is a or p

            if(ampm(ap2)){//separate (am)

                time2=time(hr2,min2);

            }
            else{//separate (pm)

                time2=time(hr2+12,min2);


            }

        }

        }

        }

    }
   else{
        return 0;
    }


    //starting time and future time diff
    diff_min= time_diff(time1,time2);
    //make ans always pos
    Abs_diff_min=Abs(diff_min);


    cout<<endl<<time_display(hr1,min1,ap1);
    cout<<" to "<<time_display(hr2,min2,ap2);
    cout<<" time difference is "<<Abs_diff_min<<" min"<<endl;


    return 0;
}

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
int Abs(int diff_min){//the fuction if Abs is a int
       if(diff_min>0){
           return diff_min;
        }
       else{
           return (diff_min*-1);
       }
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
