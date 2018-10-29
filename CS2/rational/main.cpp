#include <iostream>
#include "rational.h"

using namespace std;

int main()
{

    rational r1(1,2);
    //rational choosen by me can be change once i ask user if he want to change it
    rational r2(1,2);
    //rational choosen by me can be change once i ask user if he want to change it
    char choice;
    //choice is the users choice on which rational he want to chnage or if he want to exit the prgram
    while(choice!='x'){
        //only gets out if user press x or any other key besides 1 or 2

        report(r1,r2);
        //this does the math using the overloads and prints out the results

     choice=get_choice();
     //this asks user if they want to change an input or exist from the program

     switch(choice){
     case'1': r1.r_input();
         //first rational change
         break;
     case'2': r2.r_input();
         //second rational changed
         break;
     case'x': choice='x';
         //choose to exit
         break;
     default: choice='x';
         //any other key exit
         break;
     }

    }
}
