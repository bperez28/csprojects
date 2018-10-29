#include "arrays.h"
#include <iostream>

using namespace std;

arrays::arrays()
{

}
void _init_1d(int numused[],int m_row){
    for(int i=0; i<=m_row; i++){
        numused[i]=i;
    }
}
void _copy_array(int old[], int _new[], int &pos){
    //this copies an array to another

    for(int i=0;i<=pos; i++){

       _new[i]=old[i];

    }
}

void _shift_left(int a[],int &numused, int pos){
    //this shifts array on position to left
    pos=pos-1;
    for(int i=0; i<numused;i++){
     a[i]=a[pos+i];


    }
    //subtracts position to numused
 numused=numused-pos;
}


int _search(int a[],int numused, int key){
    //this searhces for a key in array
    for(int i=0;i<numused;i++){
        if(a[i]==key){
        return i;
        }
    }
    return -1;
}

void _rev(int a[], int numused){
    //reverses array

     for( int i=numused;i>=0;i--){
                a[i];

     }


}

int _search_rev(int a[], int numused,int key){
    //searches array key in reverse
    for(int i=numused; i>=0;i--){
        if(a[i]==key){
        return i;
        }
    }
    return -1;
}

void _print_array(int a[], int numused){
    //prints array with no curser
    for(int i=0;i<=numused;i++){
        cout<<a[i]<<" ";
    }
}

void _print_array_rev(int a[], int numused){
    //prints array in reverse
    for(int i=numused;i>=0;i--){
        cout<<a[i]<<" ";
    }
}


void _append_array(int a[], int& numused, int iteam){
    // add key to end of arrray
    a[numused+1]=iteam;

    numused=numused+1;

}

void _insert_on_pos(int a[],int& numused,int pos, int iteam){
    //it inserts key in position
    a[pos-1]=iteam;

}

void _insert_after_array(int a[],int& numused,int pos, int iteam){
    //inserts key after array

    for(int i=numused; i>pos-1; i--){
        a[i+1]=a[i];

    }
    a[pos]=iteam;

    for(int i=pos+1; i>0; i--){
        a[i];
    }
    _rev(a,numused);
    numused=numused+1;
}

void _insert_before_array(int a[],int &numused,int pos, int iteam){
    //inserts key before array

    for(int i=numused; i>=pos-1; i--){
        a[i+1]=a[i];

    }
    a[pos-1]=iteam;

    for(int i=pos; i>=0; i--){
        a[i];
    }
    _rev(a,numused);
    numused=numused+1;

}
void _asending_array(int a[],int &numused){
    //asends array to least to greatest

    if(numused/2){

    for(int i=0; i<numused; i++ ){

        if(a[i]>a[i+1]){
            _swap_array(a,numused,i,i+1);
        }


    }

    }



}
void _delete_array(int a[], int &numused, int pos){
    //deletes a position of anarray
    cout<<pos<<" ";
if(pos==numused){
    pos=0;
}

    for(int i=0; i<pos; i++){
        a[i];


    }
    for(int i=pos; i<=numused;i++){
        a[i]=a[i+1];

    }
//    if(pos<1){
//        pos=0;
//    }
    numused=numused-1;




}
void _swap_array(int a[], int &numused, int pos1, int pos2){
    //this i made to make assending array easier
    //what it does is swaps one position to another given
    int a1;
    int b;
    a1=a[pos1];
    b=a[pos2];

    a[pos1]=b;

    a[pos2]=a1;


}
void _ge(int a[],int &numused, int iteam){
    //gives the greatest key and stores it in position 0
    for(int i=0; a[i]<iteam; i++ ){
        a[0]=a[i+1];


    }
    numused=0;

}

void _delete_duplicate(int a[], int &numused){
    //this deletes duplicate keys in array
    //i use a copy , asending, search in reverse and delete arrays
    int b[numused];
    int n;
    int m;
    _copy_array(a,b,numused);
    _asending_array(b,numused);
    for(int i=0; i<=numused; i++){

        if(b[i]==b[i+1]){

            n=b[i+1];


        }
    }

    m=_search_rev(a,numused,n);
    _delete_array(a,numused,m);


}
void _print_curser(int a[], int  &numused, int pos){
    //this prints a curser on the position
    for(int i=0;i<=numused;i++){

        if(i==pos){
           cout<<"["<<a[i]<<"] ";
        }
        else{
            cout<<a[i]<<" ";

        }

    }
    cout<<endl;

}

void _choice_print_curser(int a[],int numused){


char c=' ';
//choice of user
 int pos(0);
 //old position
 int new_pos(1);
 //new position
    while(!(c=='x')){

        //prints curser
         _print_curser(a,numused,new_pos);



        int n;

        cout<<":";
        cin>>c;
        //c is user choice on what to run
    switch (c){
    case 'n': pos=new_pos+1;
        //moves curser to the next key
        new_pos=pos;
        break;
    case 'p': pos=new_pos-1;
        //move curser to the prevous key
        new_pos=pos;
        break;
    case 'd': _delete_array(a,numused,new_pos);
        //delets array the curser is on
        break;
    case 'b': n=_input_for_key(new_pos+1);
        _insert_before_array(a,numused,new_pos+1,n);
        //inserts a key before the curser
        break;
    case 'a': n=_input_for_key(new_pos+1);
        _insert_after_array(a,numused,new_pos+1,n);
        //inserts a key after the curser
        break;
    case'i': n=_input_for_key(new_pos+1);
        _insert_on_pos(a,numused,new_pos+1,n);
        //inserts key in curser
        break;
    case 'e': n=_input_for_key(new_pos);
        _append_array(a,numused,n);
        //inserts new key at the end of array
        break;
    case 'r': _shift_right(a,numused,new_pos+1);
         //shifts right on position of array
        break;
    case 'l': _shift_left(a,numused,new_pos+1);
        //this shifts array on position to left
        break;
    case 't': _delete_duplicate(a,numused);
        //this deletes duplicate keys in array
        break;
    case 's': _asending_array(a,numused);
        break;
    default:
            c='x';

        break;
        cout<<"in switch";

    }
    if(new_pos>numused){
        cout<<"numused"<<endl;
        //this is to exit out if curser gets greater than numused
//        c='x';
    }

    if(new_pos<0){
        //this exit out if curser gets smaller than 0
        c='x';
    }



    }
}
int _input_for_key(int pos){
    //this is used to in put key for selected array function
    int n;
    cout<<"key"<<" : ";
    cin>>n;
    return n;
}
void _shift_right(int a[], int &numused, int pos){

    int b[numused];
    _copy_array(a,b,numused);
    numused=numused+1;
    for( int i=pos-1; i<numused; i++){
        a[i+1]=b[i];
    }
}
