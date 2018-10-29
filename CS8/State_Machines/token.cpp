#include "token.h"
#include <iostream>

using namespace std;

Token::Token()
{
    _token.clear();
    _type=-1;
}

Token::Token(string str, int type){
    _token=str;
    _type=type;
    //0 is alpha
    //1 is numbers
    //2 is spaces
    //3 is dots
    //-1 is unknown

}

int Token::type(){
    //0 is alpha
    //1 is numbers
    //2 is spaces
    //3 is dots
    //-1 is unknown
    return _type;
}

string Token::type_string(){

    switch(_type){
    case 0: return "Alpha";break;
    case 1: return "Number";break;
    case 2: return "Unwanted"; break;
    case 3: return "Dot"; break;
    default: return "Unknown";break;
    }

}

string Token::Token_str(){
    return _token;

}
