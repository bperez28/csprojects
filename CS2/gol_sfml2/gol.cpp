#include "gol.h"
#include <iostream>
#include <fstream>
#include "constants.h"

using namespace std;



void gol::set(int row, int col)
{
    //this sets the coordinates to hold in ann object
    _r=row;
    _c=col;

}

void gol::get(int &mrow, int &mcol){
    mrow=m_row;
    mcol=m_col;
}
void gol::_random_(int a[][max_col]){
    for(int i=0; i<m_row; i++){
        for(int j=0; j<m_col;j++){
            a[i][j]=rand()%2;
        }
    }
}


void gol::check_around_8(int a[][max_col]){

    int temp[m_row][max_col];

    for(int i=0; i<m_row;i++){
        for(int j=0; j<m_col;j++){
            if((a[i][j]==1 || a[i][j]==0) && _count_n(a,i,j)<2){
                temp[i][j]=0;
            }
            else
                if(a[i][j]==1 && _count_n(a,i,j)==2){
                    temp[i][j]=1;
                }


                else
                    if(a[i][j]==0 && _count_n(a,i,j)==2){
                        temp[i][j]=0;
                    }


                    else
                        if((a[i][j]==1 || a[i][j]==0) && _count_n(a,i,j)==3){
                            temp[i][j]=1;
                        }
                        else{
                            if((a[i][j]==1 || a[i][j]==0) && _count_n(a,i,j)>3){
                                temp[i][j]=0;
                            }
                        }
        }
    }

    _copy_2d(a,temp);
//    next(_r,_c,m_row,m_col);

}
int _count_n(int a[][max_col],int _r, int _c){
    int count =0;
    if(a[_r+1][_c-1]==1)
        count++;
    if(a[_r+1][_c]==1)
        count++;
    if(a[_r+1][_c+1]==1)
        count++;
    if(a[_r][_c-1]==1)
        count++;
    if(a[_r][_c+1]==1)
        count++;
    if(a[_r-1][_c-1]==1)
        count++;
    if(a[_r-1][_c]==1)
        count++;
    if(a[_r-1][_c+1]==1)
        count++;

    return count;

}

void next(int &_r, int &_c, int m_row, int m_col){
    //next is a function that moves the postion to the next one reused from the 2d array progrm
    //_c is the position and its added by one to move to the next position
    _c=_c+1;

    //if position is trying to go over max of col it moves to the next row
    if(_c>=m_col){
        _c=0;
        _r=_r+1;

        //if rowis trying to pass the max row it just stays there and returns -1 to notify
        if(_r>=m_row){
            _r=0;
            _c=0;


        }

    }

}

void gol:: if_statements(int a[][max_col],int &c){
    //the if_statement passes c by refernce to every coordinate add all neighbors with 1s
    if(a[_r][_c]==1){
        c=c+1;
    }

}

void gol::print_2d_array(int a[][max_col]){
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

void gol::pattern(int a[][max_col]){
    a[5][2]=1;
    a[5][3]=1;
    a[5][4]=1;

}

void _init_two_d(int two_d[][max_col], int m_row, int m_col){
    //this initilized 0s adds gutter
    for(int row=0; row<m_row;row++){
        for(int col=0; col<m_col; col++){
            two_d[row][col]=0;
        }
    }
}

bool gol::_load(int a[][max_col]){
    ifstream f;
    f.open("saved_file.txt");
    if (f.fail()){
        cout<<"file "<<FILE_NAME<<" failed to open for reading."<<endl;
        return false;
    }
    //file is open and ready to write to.
    //file format: numused, followed by array elements:

    //    f>>numUsed;

    for (int i = 0; i<m_row; i++){
        for(int j=0; j<m_col; j++){
            f>>a[i][j];
        }
    }

    f.close();
    return true;

}

bool gol::_save(int a[][max_col]){
    ofstream f;
    f.open("saved_file.txt");
    if (f.fail()){
        cout<<"file "<<FILE_NAME<<" failed to open for writing."<<endl;
        return false;
    }
    //file is open and ready to write to.
    //file format: numused, followed by array elements:

    //    f<<numUsed<<endl;
    for (int i = 0; i<m_row; i++){
        for(int j=0; j<m_col; j++){
            f<<a[i][j]<<endl;
        }
    }

    f.close();
    return true;
}

void _copy_2d(int a[][max_col], int b[][max_col]){
    for(int i=0; i<m_row; i++){
        for(int j=0; j<m_col; j++){
            a[i][j]=b[i][j];
        }

    }
}


