#include "my_array_extra.h"
#include <iostream>

using namespace std;

my_array_extra::my_array_extra()
{

}
void _print(int a[][]){
    for(int i=0; a[i]!=NULL;i++){
        cout<<a[i];
    }
    cout<<endl;
}

void numused(int a[][]){

       for(int i=0; a[i][i]!=NULL;i++){
        cout<<a[i];
         if(a[i][i]=NULL){
             return i;
         }

       }



}

void _init_array(int a[][]){
    for(int i=0; a[i]!=NULL;i++){
        a[i]=0;
    }
}
