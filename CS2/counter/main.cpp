#include <iostream>
#include "counter_f.h"


using namespace std;

int main()
{
    cout<<"--------------------------"<<endl;

     char b=' ';
    counter_f num;

    do{

        b=choice();

    switch(b){
    case '+': num.inc();
        break;
    case '-': num.dec();
        break;
    case 'x': num.exist();
        break;
    case 'r': num.reset();
        break;
    }
    num.negative();
    num.print();
    cout<<endl;

    }while(b!='x');
    return 0;

}
