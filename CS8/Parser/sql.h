#ifndef SQL_H
#define SQL_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include "parse.h"
#include "../State_Machines/ftokenizer.h"
#include "../State_Machines/token.h"
#include "../BTrees/array_functions.h"
#include "../BTrees/map.h"
#include "../BTrees/mmap.h"
#include "../BTrees/pair.h"
#include "../binary_file_fun/file_record.h"
#include "../binary_file_fun/utilities.h"
#include "../binary_file_fun/consts.h"
#include "../Parser/table.h"
using namespace std;

class SQL
{
public:
    SQL(string file);

};

SQL::SQL(string file){
    //this uses the file and reads line by line and later calls parse class
    ifstream f(file);
     string input;
    if(f.is_open()){
    while(getline(f,input)){
        //the rest of this was in my main

    Parse p(input);

    if(p.get_parse_tree()["command"].at(0)=="make"){
        Table t(p.get_parse_tree()["table_name"].at(0),p.get_parse_tree()["fields/values"]);

    }else if(p.get_parse_tree()["command"].at(0)=="insert"){
        Table t(p.get_parse_tree()["table_name"].at(0));
        t.insert(p.get_parse_tree()["fields/values"]);

    }else if(p.get_parse_tree()["command"].at(0)=="select"){
         Table t(p.get_parse_tree()["table_name"].at(0));
         t.select(p.get_parse_tree()["fields/values"],p.get_parse_tree()["condition"]);


    }else{
        cout<<"doesnt contain"<<endl;
    }
    }
    }
}

#endif // SQL_H
