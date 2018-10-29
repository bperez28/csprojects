#include <iostream>
#include "date_class.h"
#include"../../Dropbox/date_library/my_dates_library.h"

using namespace std;

int main()
{

    date_class d1;
      d1.set(5,2,2017);
      //first date i choose
    date_class d2;
     d2.set(7,11,2017);
     //second date i choose
    int n=10;
    //number of days add or sub i choose
    char choice=' ';
    // users choice on which date to change or number of days being added and sub
while(choice!='x'){
//loop gets out if user picks x or any other character beside given

    report(d1,d2,n);
    //this fuction does the math and prints out results

 choice=get_choice();
 //this is a input fuction asking users choice on which date to change or number of days being added and sub

 switch(choice){
 case'1': d1.d_input();
     break;
     //changing first date
 case'2': d2.d_input();
 break;
     //changing second date
 case'3': n=n_input();
     break;
     //changing number of days being added and sub
 case'x': choice='x';
     break;
     //getting out of program
 default: choice='x';
     break;
 }

}
cout<<"out of program"<<endl;
return 0;
}
