#include <iostream>
#include "token.h"
#include "stokenizer.h"
#include "ftokenizer.h"
#include <cstdlib>
#include <iomanip>

using namespace std;

void test_f_tokenize_simple();
void test_s_tokenize_simple();
int main()
{
    test_s_tokenize_simple();

}
void test_s_tokenize_simple(){


    string s = "it was the night of october 17th. pi was still 3.14.";
           STokenizer stk(s);
           Token t;
           //The all too familiar golden while loop:

           stk>>t;

           while(stk.more()){

               //process token here...
               cout<<setw(10)<<t.type_string()<<setw(10)<<t;
              cout<<endl;
               t = Token();

               stk>>t;
           }


}
void test_f_tokenize_simple(){

    Token t;

    FTokenizer ftk("/Users/Bryan/Dropbox/CS8/State_Machines/solitude.txt");

    ftk>>t;

    int token_count = 0;
    while (ftk.more()){

        if (t.type_string()=="Alpha" ){
             token_count++;
            cout<<setw(10)<<token_count
                <<setw(3)<<left<<":"<<setw(25)<<left<<t.Token_str()
                <<t.type_string()
                <<endl;
        }
        ftk>>t;
    }
    cout<<"Tokens Found: "<<token_count<<endl;
    cout<<"=========="<<endl;

}
