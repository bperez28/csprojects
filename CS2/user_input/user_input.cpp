#include "user_input.h"
#include <iostream>
using namespace std;

user_input::user_input()
{

}
char get_user_input(){
char c;
    cout<<"user input: ";
    cin>>c;

    return c;

}

char switch_input(){
    char c;
    switch (c){
    case 1: cout<<"c";
        break;

    }

}

void print(char c){
    cout<<c;
}
