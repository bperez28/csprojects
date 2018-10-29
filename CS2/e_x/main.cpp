#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int i=1;
    double num;
    double nem(1);
    double den(1);
    double e(1);
    double first(1);
    double new_e;
    cout<<"number: ";
    cin>>num;
    while(i>100){
        new_e=new_e+e;
        e=(new_e*num)/i;
        i++;
cout<<e;
    }

    return 0;
}
