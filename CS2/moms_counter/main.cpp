#include <iostream>
#include "counter.h"

using namespace std;
int main()
{
          char choice=' ';
   while(choice!='x'){


       choice=get_choice();
       counter num;

       switch(choice){
       case'a': num.ones();
           break;
       case's': num.five();
       break;
       case'd': num.ten();
           break;
       case'f': num.f();
           break;
       case'g': num.th();
           break;
        case 'q': num.cent();
           break;
       case'w': num.fivecent();
           break;
       case'e': num.tcent();
           break;
       case'r': num.fcent();
           break;
       default: choice='x';
           break;
       }
       num.print();
       cout<<endl;


   }
   cout<<"out of program"<<endl;
    return 0;
}
