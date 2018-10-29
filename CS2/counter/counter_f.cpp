#include "counter_f.h"
#include <iostream>


using namespace std;

int counter_f::input()
{
    int r;
    cout<<"number: ";
    cin>>r;
    return r;
}

int counter_f::inc(){
    r++;
    return r;

}

int counter_f::dec(){
    r--;
    return r;
}

char counter_f::exist(){
    return 'x';
}

int counter_f::reset(){
    r=0;
    return r;
}

void counter_f::print(){
    cout<<"new number:"<<r;
}

void counter_f::negative(){
    if(r<0){
        char c;
        while(c!='r'){
            c=negative_choice();
        }
        r=0;
    }
}

char choice(){
    char i;
cout<<"increase +, decrease -, reset r, exist x"<<endl;
cin>>i;
return i;
}

char negative_choice(){
    char i;
cout<<"number is negative reset with r"<<endl;
cin>>i;
return i;
}
