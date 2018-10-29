#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>

using namespace std;

class Token
{
public:

    int alpha=0;
    int numbers=1;
    int spaces=2;
    int dots=3;
    int unknown=-1;
    Token();
    Token(string str, int type);
    int type();
    string type_string();
    string Token_str();
    friend ostream& operator <<(ostream& outs, Token& t){
        outs<<"[";
        outs<<t._token;
        outs<<"]";

    }

private:
    string _token;
    int _type;


};

#endif // TOKEN_H
