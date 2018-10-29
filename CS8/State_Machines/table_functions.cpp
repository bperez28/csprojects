#include "table_functions.h"
#include <iostream>
#include <cstdlib>

using namespace std;

table_functions::table_functions()
{

}
//Fill all cells of the array with -1
void table_functions::init_table(int _table[][MAX_COLUMNS]){
    for(int i=0; i<MAX_ROWS;i++){
        for(int j=0; j<MAX_COLUMNS;j++){
            _table[i][j]=-1;
        }
    }

}

//Mark this state (row) with a 1 (success)
void table_functions::mark_success(int _table[][MAX_COLUMNS], int state_row){
    _table[state_row][0]=1;


}

//Mark this state (row) with a 0 (fail)
void table_functions::mark_fail(int _table[][MAX_COLUMNS], int state_row){
    _table[state_row][0]=0;
}

//true if state is a success state
bool table_functions::is_success(int _table[][MAX_COLUMNS], int state_row){
    if(_table[state_row][0]==1){
        return true;
    }else if(_table[state_row][0]==0){
        return false;
    }
}

int table_functions::check_table(int _table[][MAX_COLUMNS], int& start_state, string& token, string buffer, int& pos){
   int state=-1;
    if(start_state==Number_starts){

        state=check_num_table(token,buffer,pos,_table);

    }
    if(start_state==Alpha_starts){

        state=check_alpha_table(token,buffer,pos,_table);

    }
    if(start_state==Space_starts){

        state=check_space_table(token,buffer,pos,_table);

    }
    if(start_state==Dot_starts){
        state=check_dot_table(token,buffer,pos,_table);
    }

    return state;
}
//checks the table if number or dot state
 int table_functions::check_num_table(string& token, string _buffer, int pos, int _table[][MAX_COLUMNS]){
     int col=12;
     for(char i='0'; i<='9';i++){

         if(_buffer.at(pos)==i){
              token=token+i;
             col=i-'0';

         }
     }
    if(col==12){
     if(_buffer.at(pos)=='.'){
          token=token+'.';
         col=10;

     }
    }


     col++;

     return _table[Number_starts][col];
 }
 //checks if dot found check if its a number
   int table_functions::check_dot_table(string& token,string buffer,int pos,int _table[][MAX_COLUMNS]){
       int col=12;
       for(char i='0'; i<='9';i++){

           if(buffer.at(pos)==i){
                token=token+i;
               col=i-'0';

           }
       }
       col++;
    return _table[Dot_starts][col];
   }
   //checks for bot cap and lower case alpha
   int table_functions::check_alpha_table(string& token, string _buffer,int pos,int _table[][MAX_COLUMNS]){

            int col=29;

            for(char c='A'; c<='Z';c++){

                if(_buffer.at(pos)==c){
                    token=token+c;
                col=c-'A';
                col++;

                }
            }
            if(col==29){
                for(char c='a'; c<='z';c++){

                    if(_buffer.at(pos)==c){
                        token=token+c;

                    col=c-'a';
                    col++;

                    }
                }
            }
       return _table[Alpha_starts][col];

   }

//checks for spaces returns state
 int table_functions::check_space_table(string& token,string _buffer,int pos,int _table[][MAX_COLUMNS]){
     int col=2;
     if(_buffer.at(pos)==' '){
         token=' ';
         col=1;
     }else if(_buffer.at(pos)=='\t'){
         token='\t';
         col=1;
     }else if(_buffer.at(pos)=='"'){
         token='"';
         col=1;
     }
     return _table[Space_starts][col];
 }

//Mark a range of cells in the array.
void table_functions::mark_cells(int current_row, int _table[][MAX_COLUMNS], int from, int to, int next_row){
    for(int i=from+1; i<=to+1; i++){
        mark_cell(current_row,_table,i,next_row);
    }

}

//makes cells
void table_functions::mark_cells(int row, int _table[][MAX_COLUMNS], char c_s, char c_e, int state){
  int i=20;
  if(c_s=='.'){
      i=11;
    mark_cell(row,_table,i,state);
  }else if(c_s==' '){
      i=1;
      mark_cell(row,_table,i,state);
}else{
      i=1;
      while(c_s!=c_e){     
         mark_cell(row,_table,i,state);
         c_s++;
         i++;
      }
       mark_cell(row,_table,i,state);

}

}

//Mark this row and column
void table_functions::mark_cell(int row, int table[][MAX_COLUMNS], int column, int state){
    table[row][column]=state;

}

//This can realistically be used on a small table
void table_functions::print_table(int _table[][MAX_COLUMNS]){
    for(int i=0; i<=MAX_ROWS;i++){
        for(int j=0; j<=MAX_COLUMNS;j++){
            cout<<"["<<_table[i][j]<<"]";
        }
        cout<<endl;

    }

}

//show string s and mark this position on the string:
//hello world   pos: 7
//      ^
void table_functions::show_string(string s, int _pos){
    for(int i=0; i<=s.length()-1;i++){
        cout<<s.at(i);
    }
    cout<<endl;
    for(int i=0; i<=s.length()-1;i++){
        if(i!=_pos){
        cout<<" ";
        }else{
            cout<<"^";
        }

    }
    cout<<endl;

}
