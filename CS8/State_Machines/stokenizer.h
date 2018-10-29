#ifndef STOKENIZER_H
#define STOKENIZER_H
#include "token.h"
#include "table_functions.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class STokenizer
{
public:

    STokenizer();
    STokenizer(string str);
    string get_string();
    int get_pos();
    bool more();            //true: there are more tokens
    //-- big three --

    //---------------
    //extract one token (very similar to the way cin >> works)
    friend STokenizer& operator >> (STokenizer& s, Token& t){
        string str;
        table_functions table_fun;

        if(s.get_token(table_fun.Alpha_starts,str)){
            t=Token(str,t.alpha);
            return s;
        }else if(s.get_token(table_fun.Space_starts,str)){
            t=Token(str,t.spaces);
               return s;
        }
        else if(s.get_token(table_fun.Number_starts,str)){
             t=Token(str,t.numbers);
                return s;
        }
        else if(s.get_token(table_fun.Unknown,str)){
            t=Token(str,t.unknown);
            return s;
        }


    }

    //set a new string as the input string
    void set_string(string str);

//private:
    static int _table[MAX_ROWS][MAX_COLUMNS];
     table_functions table_fun;
    //create table for all the tokens we will recognize
    //                      (e.g. doubles, words, etc.)
    void make_table();

    //extract the longest string that match
    //     one of the acceptable token types
    bool get_token(int start_state, string& str);
    //---------------------------------
    string _buffer;       //input string
    string token_str; //token string
    int _pos=0;                       //current position in the string

};

#endif // STOKENIZER_H
