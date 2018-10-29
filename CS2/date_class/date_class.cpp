#include "date_class.h"
#include"../../Dropbox/date_library/my_dates_library.h"
#include <iostream>
using namespace std;


void date_class::set(const int &m, const int &d, const int &y)
{
    //holds three varaiables
_m=m;
_d=d;
_y=y;

}
date_class::date_class(){
//empty
 }

date_class operator +(const date_class& d1,const int& n ){
    //adds days to date
return d1.add_date(n);

}

date_class operator -(const date_class& left,const int& n ){
    //subtracts days of date
       return left.sub_date(n);
}

int  operator -(const date_class& left, const date_class& right ){
    //gets diff of two dates
       int n=left.diff_date(right);
       return n;
}


date_class date_class::d_input(){
//date inpout
        date_class d1;
    date_input(_m,_d,_y);
    d1.set(_m,_d,_y);
    return d1;
}

void date_class::d_output()const{
//date output
    display_date(_m,_d,_y);
 }
void date_class::num_output(){
   //number output
   int n= _d;

    n_output(n);
}

date_class date_class::add_date(const int &n)const{
//adds dates
     date_class d1;
     //fuction adds dates by n days
   c_add_date_n_days(_m,_d,_y,d1._m,d1._d,d1._y,n);
  //returns date_class
   return d1;


}
date_class  date_class::sub_date(const int& n)const{

     date_class d1;
         //fuction sub dates by n days
    c_sub_date_n_days(_m,_d,_y,d1._m,d1._d,d1._y,n);
      //returns date_class
 return d1;

}
int  date_class::diff_date(const date_class & d2)const{
     int d1;
     //difference fuction used in other program
    d1=c_diff_date_n_date(_m,_d,_y,d2._m,d2._d,d2._y);
     //returns date_class
    return d1;

}

void date_class::dow()const{
    c_dow(_m,_d,_y);

}

int n_input(){
    //reused function to input from previous program
    return num_input();
}

char get_choice(){
    //get users choice on which date or number of days to add and sub to change
    char c;
    cout<<endl;
    cout<<endl;
    cout<<"change [1],[2] or [3]"<<endl;
    cout<<"exist [x]"<<endl;
    cin>>c;
    return c;
}

void report(const date_class& d1,const date_class& d2, const int& n){
    //report does the math and reports result of adding dates subtracting dates and date difference

    date_class add_date;
    date_class sub_date;
   int date_diff;
   //using overloading operations to do the math
    add_date=d1+n;
    sub_date=d1-n;
    date_diff=d1-d2;

    //showing user the dates
    cout<<endl<<endl;
    cout<<"[1]first date:"<<endl;
    d1.d_output();
    cout<<" ";
    d1.dow();
    cout<<endl;
    cout<<endl;
    cout<<"[2]second date: "<<endl;
    d2.d_output();
    cout<<" ";
    d2.dow();
    cout<<endl;
    cout<<endl;

//showing n number of days to add and subtract
    cout<<"[3]number: "<<endl;
    cout<<n<<endl<<endl;

    //print added date
    cout<<"add date: "<<endl;
    d1.d_output();
    cout<<" +"<<n<<"days = ";
    add_date.d_output();
    cout<<" ";
    add_date.dow();
    cout<<endl<<endl;

    //print subtracted dates
    cout<<"sub date: "<<endl;
    d1.d_output();
    cout<<" -"<<n<<"days = ";
    sub_date.d_output();
    cout<<" ";
    sub_date.dow();
    cout<<endl<<endl;

    //print date difference
    cout<<"date difference: "<<endl;
    d1.d_output();
    cout<<" - ";
    d2.d_output();
    cout<<" = ";
    cout<<date_diff<<endl<<endl;
}
