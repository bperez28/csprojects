#include "my_num_base.h"
#include <iostream>

using namespace std;

My_num_base::My_num_base()
{

}
void add(char a[], char b[], char result[], int base){

int n;
int r;
int nn;
int rr;
    for(int i=0; a[i]>0;i++){

        convert_base(a[i],n,r,base);
        for(int w=0; b[w]>0; w++){
            convert_base(b[w],nn,rr,base);
            for(int r=0; result[r]>0; r++);
            result[r]=nn+n;


        }
    }


}

void convert_base(char a,int& n, int &r, int base){
    switch(base){
    case 2: convert_base2(a,n,r,base);
        break;
    case 10: convert_base10(a,n,r,base);
        break;
    case 16: convert_base16(a,n,r,base);
        break;
    }

}
void _add_pad_rev(char a[],int i){
    cout<<i;
    for(int n=i;n>0;n++){
        if(n>0){
            a[n]=-1;
        }
        for(int w=0;a[w]<0; w--){
        a[w]=a[i];
        }

    }
}
void strlength(char a[],int i){


    i=0;
    while(a[i]!='\0'){
       cout<<a[i];
       i++;
   }
}

void convert_base2(char a, int& n, int & r, int base){
    n=a-'0';
    r=n%base;
    n=n/base;
}

void convert_base10(char a, int& n, int & r, int base) {
    n=a-'0';
    r=n%base;
    n=n/base;

}

void convert_base16(char a, int& n, int & r, int base){
    switch(a){
    case 'A': a='11';
                break;
    case 'a': a='11';
                break;
    case 'B': a='12';
                break;
    case 'b': a='12';
                break;
    case 'C': a='13';
                break;
    case 'c': a='13';
                break;
    case 'D': a='14';
                break;
    case 'd': a='14';
                break;
    case 'E': a='15';
                break;
    case 'e': a='15';
                break;
    case 'F': a='16';
                break;
    case 'f': a='16';
                break;


    }
    n=a-'0';
    r=n%base;
    n=n/base;


}
