#include "stokenizer.h"
#include "token.h"
#include "table_functions.h"
#include <iostream>
#include <cstdlib>

using namespace std;
int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

STokenizer::STokenizer()
{
   //this makes the table with states
    make_table();

}
STokenizer::STokenizer(string str){
//_buffer is the string in which we will get at postion
// to check if it has a token
_buffer=str+" ";
make_table();
}
 bool STokenizer::more(){
     //if the position reaches the string length it return false
     if(_pos!=_buffer.length()){
         return true;
     }else{
         return false;
     }
 }
int STokenizer::get_pos(){
   //to see the postition of stokenizer
    return _pos;
}
string  STokenizer::get_string(){
    //it returns string its using to token
    return _buffer;
}

void STokenizer::set_string(string str){
    //to set a new string to get token
    _buffer=str;
}
void STokenizer::make_table(){
//makes all the array -1;
    table_fun.init_table(_table);

//state 0 is to check if theres a number token if theres a dot go to state 2
       table_fun.mark_cells(0, _table, '0','9', 1);    //state [0] --- 0-9 ---> [1]
       table_fun.mark_cells(0, _table, '.', '.', 2);  //state [0] --- '.' ------> [2]
// state 1 is if the last char was a number check if its a number if dot go to state 2
       table_fun.mark_cells(1, _table,'0','9', 1);    //state [1] --- DIGITS ---> [1]
       table_fun.mark_cells(1, _table, '.', '.', 2);  //state [1] --- '.' ------> [2]

 //state 2 if dot was found look for number
       table_fun.mark_cells(2, _table, '0','9', 3);    //state [2] --- DIGITS ---> [3]
 //state 3 if there was a number in state two
       table_fun.mark_cells(3, _table, '0','9', 3);    //state [3] --- DIGITS ---> [3]
//state 4 if its not a number see if its a cap alpha or lower case
       table_fun.mark_cells(4, _table, 'A', 'Z', 4);  //state [4] --- 'A-Z' ------> [4]
       table_fun.mark_cells(4, _table, 'a', 'z', 4);  //state [4] --- 'a-z' ------> [4]

//state 6 if its a space
       table_fun.mark_cells(6, _table, ' ', ' ', 6);  //state [6] --- ' ' ------> [6]



}
 bool STokenizer::get_token(int start_state, string& str){
     //this is if start_state does equal -1
     //it means anything that is to unknown
     if(start_state!=-1){

         //the i is used to keep check of state 2
     int i=0;
     //this is if state value does change
     int state=-1;
//this checks the table and returns the state
     state=table_fun.check_table(_table,start_state, str, _buffer, _pos);

     //if the first check is found
     if(state!=-1){

         while(state!=-1){


             _pos++;
             if(state==2){
                 //if dot found check in state 2
                 start_state=2;
                 i++;

             }
               //if _pos is about to go out of bound
             if(_pos<=_buffer.length()-1){
                //this checks the table and returns the state
                 state=table_fun.check_table(_table,start_state, str, _buffer, _pos);

             }else{
                //make it get out of the while loop if its about to go out of bound
                 state=-1;

             }

             if(state==3){
                 //this is if the state is 3 to i++
                 i++;
             }


}
         //this means if a dot by it self was found
         //and it doesnt have 2 numbers following it
         if( start_state==2 && i==1){
             _pos--;
             return false;
         }

         return true;

}else{

        return false;

     }
}else{
         //if its an unknown

         str=_buffer.at(_pos);

         _pos++;
         return true;


 }
}
