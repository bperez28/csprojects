#include <iostream>

using namespace std;

const int max_col=100;

void _init_two_d(int two_d[][max_col],int m_row,int m_col);
void _print_2d_curser(int two_d[][max_col], int numused[], int m_row, int Col, int Row);
void _next(int & col, int & row, int numused[], int m_row);
void _prev(int & col, int & row, int numused[], int m_row);
void _up(int &col, int &row, int numused[], int m_row);
void _down(int &col, int &row, int numused[], int m_row);

// 1d array functions
void _init_1d(int numused[],int m_row);
void _copy_array(int old[], int _new[], int &num_used);
void _shift_left(int a[], int &numused, int &pos);
void _shift_right(int a[], int &numused, int pos);
int _search(int a[], int numused, int key);
void _rev(int a[], int numused);
int _search_rev(int a[], int numused,int key);
void _print_array(int a[], int numused);
void _print_array_rev(int a[], int numused);
void _append_array(int a[], int &numused, int iteam);
void _insert_on_pos(int a[], int &numused, int pos, int iteam);
void _insert_after_array(int a[], int &numused, int &pos, int iteam);
void _insert_before_array(int a[], int &numused, int pos, int iteam);
void _asending_array(int a[], int &numused);
void _delete_array(int a[], int &numused, int &pos);
void _ge(int a[], int &numused, int iteam);
void _swap_array(int a[], int &numused, int pos1, int pos2);
void _delete_duplicate(int a[], int &numused);
void _print_curser(int a[], int  &numused, int pos);
int _input_for_key(int pos);
//void _choice_print_curser(int a[], int numused);

int main()
{
    int row=3;
    int col=2;
    int m_row=5;
    int numused[m_row];
    int a[100][100];
    _init_1d(numused,m_row);
    _init_two_d(a,100,100);

    char c=' ';
    while(c!='q'){


           _print_2d_curser(a,numused,m_row,col,row);

        int num=numused[row];
        int n;
//        int b[num];



    cout<<":";
    cin>>c;
    //c is user choice on what to run
 switch(c){
 case 'n': _next(col,row,numused,m_row);
     break;
 case 'p': _prev(col,row,numused,m_row);
     break;
 case 'u': _up(col,row,numused,m_row);
     break;
 case 'd': _down(col,row,numused,m_row);
     break;
    case 'x':
        _delete_array(a[row],num,col);
                numused[row]=num;
        //delets array the curser is on
        break;
    case 'b':
        n=_input_for_key(col);
        _insert_before_array(a[row],num,col,n);
        numused[row]=num;
//        cout<<"copy2"<<endl;

        //inserts a key before the curser
        break;
    case 'a':

        n=_input_for_key(col);
        _insert_after_array(a[row],num,col,n);

             numused[row]=num;
        //inserts a key after the curser
        break;
    case'i': n=_input_for_key(col);
        _insert_on_pos(a[row],num,col,n);
             numused[row]=num;
        //inserts key in curser
        break;
    case 'e':
     n=_input_for_key(col);
        _append_array(a[row],num,n);
        numused[row]=num;

        //inserts new key at the end of array
        break;
    case 'r': _shift_right(a[row],num,col);
            numused[row]=num;
         //shifts right on position of array

        break;
    case 'l': _shift_left(a[row],num,col);
             numused[row]=num;
        //this shifts array on position to left
        break;
    case 't': _delete_duplicate(a[row],num);
             numused[row]=num;
        //this deletes duplicate keys in array
        break;
    case 's':
     _asending_array(a[row],num);
     numused[row]=num;
        break;
    default:
            c='q';
        break;

 }


 }

 cout<<endl<<endl<<"---------------------------------"<<endl;
}



void _init_two_d(int two_d[][max_col], int m_row, int m_col){
    for(int row=0; row<m_row;row++){
        for(int col=0; col<m_col; col++){
            two_d[row][col]=row*10+col;
        }
    }
}
void _print_2d_curser(int two_d[][max_col],int numused[],int m_row, int Col, int Row){

    for(int row=0; row<m_row; row++){

        for(int col=0; col<numused[row]; col++ ){

            if(Row==row && Col==col){
                cout<<"["<<two_d[row][col]<<"]";
            }
            else{
                if(two_d[row][col]>1000){
                cout<<"   "<<two_d[row][col]<<"   ";
                }
                if(two_d[row][col]>100){
                cout<<"  "<<two_d[row][col]<<"  ";
                }
            if(two_d[row][col]>0){
            cout<<" "<<two_d[row][col]<<" ";
            }



            }

        }
        cout<<endl;
    }
    cout<<endl;

}
void _next(int & col, int & row, int numused[], int m_row){
    col=col+1;
    if(col>=numused[row]){
        col=0;
        row=row+1;
        if(row>=m_row){
           row=m_row-1;
           col=numused[row-1];

        }

    }



}

void _prev(int & col, int & row, int numused[], int m_row){
    col=col-1;
    if(col<0){
        row=row-1;
        col=numused[row]-1;

        if(row<=0){
            row=1;
            col=0;
        }

    }

}

void _up(int &col, int &row, int numused[], int m_row){
    row=row-1;
    if(row<=0){
        row=1;
    }
    if(col>numused[row-1]){
        col=numused[row-1];
    }

}
void _down(int &col, int &row, int numused[], int m_row){
    row=row+1;
    if(row>=m_row){
        row=m_row-1;
    }


}



// 1d array functions

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

void _shift_left(int a[],int &numused, int &pos){
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
    a[numused]=iteam;

    numused=numused+1;

}

void _insert_on_pos(int a[],int& numused,int pos, int iteam){
    //it inserts key in position
    a[pos-1]=iteam;

}

void _insert_after_array(int a[],int& numused,int &pos, int iteam){
    //inserts key after array
    for(int i=numused; i>pos; i--){
        a[i+1]=a[i];

    }
    a[pos+1]=iteam;

    for(int i=pos-1; i>0; i--){
        a[i];
    }
    _rev(a,numused);
    pos=pos+1;
    numused=numused+1;
}

void _insert_before_array(int a[],int &numused,int pos, int iteam){
    pos=pos+1;
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

  for(int i=0; i<numused; i++){
      if(a[i]>a[i+1]){
          _swap_array(a,numused,i,i+1);

      }
      if(a[i+2]>a[i+3]){
          _swap_array(a,numused,i+2,i+3);
      }


  }
  for(int i=0; i<numused; i++){
      if(a[i]>a[i+1]){
          _swap_array(a,numused,i,i+1);

      }
      if(a[i+2]>a[i+3]){
          _swap_array(a,numused,i+2,i+3);
      }


  }

}

void _delete_array(int a[], int &numused, int &pos){
    //deletes a position of anarra

if(pos==0){
    if(numused==1){

        pos=0;

    }
    else{
        for(int i=0; i<pos; i++){
            a[i];

        }
        for(int i=pos; i<=numused;i++){
            a[i]=a[i+1];

        }
        numused=numused-1;

    }

}
else{
    for(int i=0; i<pos; i++){
        a[i];

    }
    for(int i=pos; i<=numused;i++){
        a[i]=a[i+1];

    }
     pos=pos-1;
    numused=numused-1;
}

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


int _input_for_key(int pos){
    //this is used to in put key for selected array function
    int n;
    cin>>n;
    return n;
}
void _shift_right(int a[], int &numused, int pos){

    int b[numused];
    _copy_array(a,b,numused);
    numused=numused+1;
    for( int i=pos; i<numused; i++){
        a[i+1]=b[i];
    }
}
