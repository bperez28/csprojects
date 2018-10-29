#include <iostream>

using namespace std;
//the constants:
    //overtime pay per hour over

const double p =1.5;
const double ft = 40;
int main(int argc, char *argv[])
{
    cout<<endl<<endl<<endl<<"---------------------------------" << endl;
    int hourpay = 0;
    int time = 0;
    int ot1 =0;
    int otp = 0;
    int ot2 =0;
    int t =0;

    //ot= overtime, ft= fulltime,
    //time is overall time,
    //otp is overtime pay
    //ov1 is when theres no overtime
    //ov2 is overtime


    //input:
    cout<<"how much do you get paid per hour? $ ";
    cin>>hourpay;
    //verify: hourpay >0
    if(hourpay <= 0){
        cout<<"*Error* Hourly pay must be postive number."<<endl;
        return 0;
    }
    cout<<"Amount of time worked in week: ";
    cin>>time;
    //verify: time >0
    if(time <= 0){
        cout<<"*Error* Time must be a postive number."<<endl;
        return 0;
    }

    //process: if time > ft than ft- time to get
    if(time > ft){
       //ov2 is overtime
        ot2 = time - ft;
        cout<<"Amount of over time: "<<ot2<< endl;
    }
    else{
        if(time == ft){
           //ov1 is when theres no overtime
            ot1 = 0;
            cout<<"Almost got the overtime pay."<< endl;
        }
        else{
            ot1 = ft -time;
            cout<<"No overtime pay. Needed "<<ot1<<" hours to get over time"<<endl;
        }


    }
    if(ot2 <= 0){
        otp = 0;
    }
    else{
        //there is overtime pay
        if(ot2 > 0){
            otp = ot2*(p*hourpay);
        }
    }
    if(ot1<=0){
        t=40;
    }
    else{
        //if they work less than full time
        if(ot1>0){
            t= ft-time;
        }
    }


    // ovp is overall pay

    double ovp;
    ovp = (t*hourpay) +otp;
    cout<<"overall week pay $ "<<ovp<<endl;

    }
