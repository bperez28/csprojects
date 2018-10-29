#include "ftokenizer.h"
#include <fstream>
#include "token.h"
#include "stokenizer.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>


using namespace std;


FTokenizer::FTokenizer()
{

}
FTokenizer::FTokenizer(string fname){

    string line;
        //had to add where the file is located in the main
     ifstream _f (fname);
      if (_f.is_open())
      {
        while ( getline (_f,line) )
        {
            //line adds to all the lines
            //all lines is later used for stokenizer
        all_line=all_line+line;

        }
        //this is to know our initial all_line length
        // is it will be changing
        all_line_length=all_line.length();
        _stk.set_string(all_line);


      }else{

          cout << "Unable to open file";
      }

}

bool FTokenizer:: more(){
    //if the position isn't equal to the initial all_line length
    if(_stk.get_pos()!=all_line_length){
        return true;
    }else{
        return false;
    }

}




