#include "counter.h"
#include <iostream>

using namespace std;

counter::counter()
{

}
double counter::ones(){
    n=n+1;
    return n;

}

double counter::five(){
    n=n+5;
    return n;

}

double counter::ten(){
    n=n+10;
    return n;
}

double counter::f(){
    n=n+50;
    return n;
}

double counter::th(){
    n=n+100;
    return n;
}
double counter::cent(){
    n=n+0.01;
    return n;

}

double counter::fivecent(){
    n=n+0.05;
    return n;
}

double counter::tcent(){
    n=n+0.10;
    return n;
}
double counter::fcent(){
    n=n+0.50;
    return n;

}
void counter::print(){
if(n>0){
    cout<<"cost: ";
    cout<<n;
}
}


char get_choice(){
    cout<<"----------------------------------------------------------------------"<<endl;
    char c=' ';
    cout<<"for ones: a, for five: s, for ten: t, for fifty: d, for hundred: f"<<endl;

    cout<<"for one cent: q, for five cents: w, for ten cents: e, for fifty cents: r "<<endl;

    cout<<"press any other character to exist"<<endl;

    cin>>c;
    return c;

}
