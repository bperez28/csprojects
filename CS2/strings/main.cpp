#include <iostream>
#include "mycstrings.h"
using namespace std;

int main()
{
    char n1[1000]="34943780";
    char n2[10]="487";
    char n3[10000];


    int i;
    i=strlength(n1);
    cout<<endl<<i<<endl;

//    strcopy(n1,n3);
//    strprint(n3);

    return 0;
}
