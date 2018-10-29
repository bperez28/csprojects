#include "mycstrings.h"
#include <iostream>

using namespace std;

myCstrings::myCstrings()
{

}

int strlength(char a[]){
    int i;
   for(i=0; a[i]=NULL;i++){
    cout<<a[i];
           i=i+i;

   }
   return i;
}

void strcopy(char a[], char b[]){
    for(int i=0; a[i]!=NULL; i++){
        b[i]=a[i];

    }
    int n=strlength(a);
//    b[n]=NULL;
    cout<<n;

    cout<<endl;


}

void strprint(char a[]){
    for(int i=0; a[i]!=NULL;i++){

            cout<<a[i];


    }
    cout<<endl;
}


