#include "date_diff.h"
#include <iostream>

using namespace std;

int m_d_ony_to_days(int m, int d, int y){
    int days;
    if(leap_y(y)){
        days=m_d_Lswitch(m,d);

    }
    else{
       days= m_d_switch(m,d);

    }


    return days;

}
int m_d_Lswitch(int m, int d){
    int n;
    switch(m){
    case 1: n=d+1;
        break;
    case 2: n=d+32;
        break;
    case 3: n=d+61;
        break;
    case 4: n=d+92;
        break;
    case 5: n=d+122;
        break;
    case 6: n=d+153;
        break;
    case 7: n=d+183;
        break;
    case 8: n=d+214;
        break;
    case 9: n=d+245;
        break;
    case 10: n=d+275;
        break;
    case 11: n=d+306;
        break;
    case 12: n=d+336;
        break;

    }
    return n;

}

int m_d_switch(int m, int d){
    int n;
    switch(m){
    case 1: n=d;
        break;
    case 2: n=d+31;
        break;
    case 3: n=d+59;
        break;
    case 4: n=d+90;
        break;
    case 5: n=d+120;
        break;
    case 6: n=d+151;
        break;
    case 7: n=d+181;
        break;
    case 8: n=d+212;
        break;
    case 9: n=d+243;
        break;
    case 10: n=d+273;
        break;
    case 11: n=d+304;
        break;
    case 12: n=d+334;
        break;

    }
    return n;


}

int y_to_days(int y){
    int new_year;
    int n;
    int year_day(0);
    new_year=y-1;
    if(new_year<=0){
        year_day=0;

    }
    else{
        while(new_year>0){
            if(leap_y(new_year)){
                n=366;
            }
            else{
                n=365;
            }
            year_day=year_day+n;
            new_year--;

        }

    }

    return year_day;
}

int m_d_y_to_days(int m, int d, int y ){
    int total_days;
    total_days=m_d_ony_to_days(m,d,y)+y_to_days(y);

    return total_days;

}

bool valid_m_d_y(int m, int d, int y, char c){
    if(valid_m(m)){
    if(valid_d(d,m,y)){
        if(valid_colon(c)){
    if(valid_y(y)){
    return true;}}}}
    return false;

}

bool valid_colon(char c){
    if(c=='/'){
        return true;
    }
   return false;
}

bool valid_m(int m){
    if(m<=0){
        cout<<"months cant be negative"<<endl;
        return false;
    }
    if(m>12){
        cout<<"months cant be greater than 12"<<endl;
        return false;
    }
    return true;
}

bool valid_d(int d,int m, int y){
    if(d<0){
        cout<<"days cant be negative"<<endl;
        return false;
    }
    else{
    if(leap_y(y)){
        switch(m){
        case 1: if(d>31){
            cout<<"January only has 31 days"<<endl;
            return false;}
            break;
        case 2: if(d>29){
            cout<<"February only has 29 on leap years"<<endl;
            return false;}
            break;
        case 3: if(d>31){
            cout<<"March only has 31 days"<<endl;
            return false;}
            break;
        case 4: if(d>30){
            cout<<"April only has 30 days"<<endl;
            return false;}
            break;
        case 5: if(d>31){
            cout<<"May only has 31 days"<<endl;
            return false;}
            break;
        case 6: if(d>30){
            cout<<"June only has 30 days"<<endl;
            return false;}
            break;
        case 7: if(d>31){
            cout<<"July only has 31 days"<<endl;
            return false;}
            break;
        case 8: if(d>31){
            cout<<"August only has 31 days"<<endl;
            return false;}
            break;
        case 9: if(d>30){
            cout<<"September only has 30 days"<<endl;
            return false;}
            break;
        case 10: if(d>31){
            cout<<"October only has 31 days"<<endl;
            return false;}
            break;
        case 11: if(d>30){
            cout<<"November only has 30 days"<<endl;
            return false;}
            break;
        case 12: if(d>31){
                cout<<"December only has 31 days"<<endl;
            return false;}
            break;

        }
        return true;
    }
    else{
        switch(m){
        case 1: if(d>31){
            cout<<"January only has 31 days"<<endl;
            return false;}
            break;
        case 2: if(d>28){
            cout<<"February only has 28 on non-leap years"<<endl;
            return false;}
            break;
        case 3: if(d>31){
            cout<<"March only has 31 days"<<endl;
            return false;}
            break;
        case 4: if(d>30){
            cout<<"April only has 30 days"<<endl;
            return false;}
            break;
        case 5: if(d>31){
            cout<<"May only has 31 days"<<endl;
            return false;}
            break;
        case 6: if(d>30){
            cout<<"June only has 30 days"<<endl;
            return false;}
            break;
        case 7: if(d>31){
            cout<<"July only has 31 days"<<endl;
            return false;}
            break;
        case 8: if(d>31){
            cout<<"August only has 31 days"<<endl;
            return false;}
            break;
        case 9: if(d>30){
            cout<<"September only has 30 days"<<endl;
            return false;}
            break;
        case 10: if(d>31){
            cout<<"October only has 31 days"<<endl;
            return false;}
            break;
        case 11: if(d>30){
            cout<<"November only has 30 days"<<endl;
            return false;}
            break;
        case 12: if(d>31){
                cout<<"December only has 31 days"<<endl;
            return false;}
            break;

        }
        return true;
    }
    }

}

bool valid_y(int y){
    if(y<0){
        cout<<"years cant be negative"<<endl;
        return false;
    }
    return true;
}

bool slash(char s){
    if(s='/'){
        return true;
    }
    cout<<"use / to separate ex: mm/dd/yyyy "<<endl;
    return false;
}

bool leap_y(int y){
    if(y%400==0){
        return true;
    }
    else{
        if(y%100==0){
            return false;
        }
        else{
            if(y%4==0){
            return true;
        }
    }
        return false;

    }

}

bool valid_numbers(int n){
    if(n<0){
        cout<<"days to add cant be negative"<<endl;
        return false;
    }
    return true;
}

int  diff_date_n_date(int m1, int d1,int y1, int m2, int d2, int y2){
int new_d;
    new_d=m_d_y_to_days(m2,d2,y2)-m_d_y_to_days(m1,d1,y1);
    return new_d;

}

int days_to_years(int& d){
  int i=0;


    while(d>=365){

        if(leap_y(i)){
            d=d-366;
        }
        else{
            d=d-365;
        }
        i++;
    }
    if(leap_y(i)){
        if(d==0){
            d=366;
        }
        else{

            i=i+1;
        }
    }
        else{
       if(d==0){
           d=1;
           i=i+1;
       }
       else{
           if(d<0){
               d=-1*d;
           }
           i=i+1;

       }
    }

    return (i);

}

void y_rday_to_m(int y, int& n, int& m){
    cout<<n<<endl;

    if(leap_y(y)){
        if(n<=31){
            m=1;
            n=n;
        }
        else{
        if(n<=60){
            m=2;
            n=n-31;
        }
        else{
        if(n<=91){
            m=3;
            n=n-60;
        }
        else{
        if(n<=121){
            m=4;
            n=n-91;
        }
        else{
        if(n<=152){
            m=5;
            n=n-121;
        }
        else{
        if(n<=182){
            m=6;
            n=n-152;
        }
        else{
        if(n<=213){
            m=7;
            n=n-182;
        }
        else{
        if(n<=244){
            m=8;
            n=n-213;
        }
        else{
        if(n<=274){
            m=9;
            n=n-244;
        }
        else{
        if(n<=305){
            m=10;
            n=n-274;
        }
        else{
        if(n<=335){
            m=11;
            n=n-305;
        }
        else{
        if(n<=366){
            m=12;
            n=n-335;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
    }
    else{
        if(n<=31){
            m=1;
            n=n;
        }
        else{
        if(n<=59){
            m=2;
            n=n-31;
        }
        else{
        if(n<=90){
            m=3;
            n=n-59;
        }
        else{
        if(n<=120){
            m=4;
            n=n-90;
        }
        else{
        if(n<=151){
            m=5;
            n=n-120;
        }
        else{
        if(n<=181){
            m=6;
            n=n-151;
        }
        else{
        if(n<=212){
            m=7;
            n=n-181;
        }
        else{
        if(n<=243){
            m=8;
            n=n-212;
        }
        else{
        if(n<=273){
            m=9;
            n=n-243;
        }
        else{
        if(n<=304){
            m=10;
            n=n-273;
        }
        else{
        if(n<=334){
            m=11;
            n=n-304;
        }
        else{
        if(n<=365){
            m=12;
            n=n-333;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }

    }
}

//void days_to_m_d_y(int& m,int& d,int& y){
//    y=days_to_years(d);
//    y_rday_to_m(y,d,m);
//    m_rday_to_day(m,d,y);

//}

char display_date(int m, int d, int y){
    display_padded_int(m);
    cout<<'/';
    display_padded_int(d);
    cout<<'/';
    cout<<y;
    cout<<endl;

}

int display_padded_int(int number){
    if(number<10){
        cout<<'0'<<number;
    }
    else{
        cout<<number;
    }
}
