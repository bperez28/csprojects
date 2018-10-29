#include "mygol.h"
#include <iostream>
using namespace std;

void mygol::set(int row, int col)
{
    //this sets the coordinates to hold in ann object
    _r=row;
    _c=col;

}


int mygol::check_around_8(int a[][max_col]){

            //positions of box without the center position
            //object holds position coordinate
            mygol o;
            mygol s;
            mygol t;
            mygol fo;
            mygol fi;
            mygol si;
            mygol se;
            mygol e;

            //i returns if end of grid to get out of program
            int i;
            //c is number of neighbors around the position
            int c=0;

            //set makes the object hold the coordinate positions
            o.set(_r+1,_c-1);
            s.set(_r+1,_c);
            t.set(_r+1,_c+1);
            fo.set(_r,_c-1);
            fi.set(_r,_c+1);
            si.set(_r-1,_c-1);
            se.set(_r-1,_c);
            e.set(_r-1,_c+1);

            //the if_statement passes c by refernce to every coordinate add all neighbors with 1s
            o.if_statements(a,c);
            s.if_statements(a,c);
            t.if_statements(a,c);
            fo.if_statements(a,c);
            fi.if_statements(a,c);
            si.if_statements(a,c);
            se.if_statements(a,c);
            e.if_statements(a,c);

            //this is the rule if the neighbors add up to 3 or 2 the box on the position becomes a 1
            if(c==3 || c==2){
                a[_r][_c]=1;
            }

            //if it didnt pass the condition than it writes down a 0
            else{
                a[_r][_c]=0;

            }

           //i is to stop the program when it reaches the end
           //next is a function that moves the postion to the next one reused from the 2d array progrm
           i=next(_r,_c,m_row,m_col);
           return i;

}
int next(int &_r, int &_c, int m_row, int m_col){
    //next is a function that moves the postion to the next one reused from the 2d array progrm
    //_c is the position and its added by one to move to the next position
    _c=_c+1;

    //if position is trying to go over max of col it moves to the next row
    if(_c>=m_col){
        _c=0;
        _r=_r+1;

        //if rowis trying to pass the max row it just stays there and returns -1 to notify
        if(_r>=m_row){
           _r=m_row-1;
           _c=m_col;
           return -1;

        }
        return 0;
    }
    return 0;
}

void mygol:: if_statements(int a[][max_col],int &c){
    //the if_statement passes c by refernce to every coordinate add all neighbors with 1s
    if(a[_r][_c]==1){
        c=c+1;
    }

}

void mygol::print_2d_array(int a[][max_col]){
    //this program is reused from my 2d array project
    //simple print the 2d array
    for(int row=0;row<m_row;row++){
        for(int col=0; col<m_col;col++){

            if(col==_c && row==_r){
                cout<<"[";
                cout<<a[row][col];
                cout<<"]";
            }
            else{
                cout<<" ";
                cout<<a[row][col];
                cout<<" ";

            }
        }

        cout<<endl;

    }

    cout<<endl;

}

void mygol::load(int a[][max_col]){
    //load is in what coordinates you want 1s in
    a[5][1]=1;
    a[5][2]=1;
}

void _init_two_d(int two_d[][max_col], int m_row, int m_col){
    //this initilized 0s adds gutter
    for(int row=0; row<m_row+1;row++){
        for(int col=0; col<m_col+1; col++){
            two_d[row][col]=0;
        }
    }
}
