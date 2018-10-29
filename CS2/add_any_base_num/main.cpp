#include <iostream>
#include "my_num_base.h"
using namespace std;

int main()
{
    cout<<endl<<endl<<"======================================================="<<endl<<endl;
    int i;
    int n;
    int base;
    char a[]="1996'\0'";
    char b[]="2017'\0";
    char r[]=" ";
    base=10;
    strlength(a,i);
    cout<<"+";
    strlength(b,n);
    cout<<"=";
    cout<<endl;
    _add_pad_rev(a,i);
    _add_pad_rev(b,n);
    add(a,b,r,base);


    return 0;
}
