#ifndef FTOKENIZER_H
#define FTOKENIZER_H
#include <fstream>
#include "token.h"
#include "stokenizer.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class FTokenizer
{
public:
    string all_line;
    int all_line_length;
    FTokenizer();
    FTokenizer(string fname);
    void test_f_tokenize_simple();
    Token next_token();
    bool more();        //returns the current value of _more
    friend FTokenizer& operator >> (FTokenizer& f, Token& t){
        //uses stokenizer to do the work
               f._stk>>t;
               return f;
    }
private:

    STokenizer _stk;     //The STokenizer object to tokenize current block
    bool _more;         //if _stk position reaches all_lines length

};

#endif // FTOKENIZER_H
