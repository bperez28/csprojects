#ifndef PARSE_H
#define PARSE_H
#include "../BTrees/map.h"
#include "../BTrees/mmap.h"
#include "../State_Machines/table_functions.h"
#include "../State_Machines/stokenizer.h"
#include "../State_Machines/token.h"
using namespace std;
//const int MAX_INPUT=1000;

class Parse
{
public:
    Parse();
    Parse(string s);
    MMap<string,string> &get_parse_tree();

//private:
    const int select=1;
    const int from=2;
    const int comma=3;
    const int symbol=4;
    const int where=5;
    const int equal=6;
    const int insert=7;
    const int into=8;
    const int fields=9;
    const int values=9;
    const int  make=10;
    const int table=11;
    const int and_or=12;
    const int all=13;

    int Machine[MAX_ROWS][MAX_COLUMNS];
    vector<string> input;
    Map<string,int> map_keys;
    MMap<string,string> parse_tree;
    table_functions table_fun;

    void strtoken(string s);
    void Make_state_machine();

    void Make_keys_map();
    void verify_n_add_parse_tree();



};
 MMap<string,string>& Parse::get_parse_tree(){
     return parse_tree;
 }

Parse::Parse(){

}

Parse::Parse(string s){

    //gets the string and tokenizes it
    strtoken(s);

    //makes the state machine to use to verify
    Make_state_machine();

    //gives back the col of the item
    Make_keys_map();

    //this verifies the and makes a parse tree
    verify_n_add_parse_tree();

}

void Parse::strtoken(string s){
    Token t;

    STokenizer stk(s);
//    cout<<endl<<stk.get_string()<<endl;
//    cout<<endl<<"---------------------------------stokenizer------------------------"<<endl;

    stk>>t;

    while (stk.more()){
        //unwanted is spaces and tabs
        if(t.type_string()!="Unwanted" ){
            input.push_back(t.Token_str());
//            cout<<setw(3)<<left<<":"<<setw(25)<<left<<t.Token_str()
//               <<t.type_string()
//              <<endl;
        }
        stk>>t;
    }

}

void Parse::Make_state_machine(){
    table_fun.init_table(Machine);

    //--------------marking cells with states------------
    table_fun.mark_cell(0,Machine,select,1);
    table_fun.mark_cell(0,Machine,insert,9);
    table_fun.mark_cell(0,Machine,make,14);
    table_fun.mark_cell(1,Machine,symbol,2);
//    table_fun.mark_cell(1,Machine,all,2);
    table_fun.mark_cell(2,Machine,comma,1);
    table_fun.mark_cell(2,Machine,from,3);
    table_fun.mark_cell(3,Machine,symbol,4);
    table_fun.mark_cell(4,Machine,where,5);
    table_fun.mark_cell(5,Machine,symbol,6);
    table_fun.mark_cell(6,Machine,equal,7);
    table_fun.mark_cell(7,Machine,symbol,8);
    table_fun.mark_cell(8,Machine,comma,5);
    table_fun.mark_cell(9,Machine,into,10);
    table_fun.mark_cell(10,Machine,symbol,11);
    table_fun.mark_cell(11,Machine,fields,12);
    table_fun.mark_cell(12,Machine,symbol,13);
    table_fun.mark_cell(13,Machine,comma,12);
    table_fun.mark_cell(14,Machine,table,10);


    //----------------making success------------------
    table_fun.mark_fail(Machine,0);
    table_fun.mark_fail(Machine,1);
    table_fun.mark_fail(Machine,2);
    table_fun.mark_fail(Machine,3);
    table_fun.mark_fail(Machine,5);
    table_fun.mark_fail(Machine,6);
    table_fun.mark_fail(Machine,7);
    table_fun.mark_fail(Machine,9);
    table_fun.mark_fail(Machine,10);
    table_fun.mark_fail(Machine,11);
    table_fun.mark_fail(Machine,12);
    table_fun.mark_fail(Machine,14);
    table_fun.mark_success(Machine,4);
    table_fun.mark_success(Machine,8);
    table_fun.mark_success(Machine,13);


}

void Parse::Make_keys_map(){
    //this returns the col of the machine to check
    map_keys.insert("select",select);
    map_keys.insert("from",from);
    map_keys.insert(",",comma);
    map_keys.insert("=",equal);
    map_keys.insert("where",where);
    map_keys.insert("insert",insert);
    map_keys.insert("into",into);
    map_keys.insert("fields",fields);
    map_keys.insert("values",values);
    map_keys.insert("make",make);
    map_keys.insert("table",table);
    map_keys.insert("and",and_or);
    map_keys.insert("or",and_or);
//    map_keys.insert("*",all);



}

void Parse::verify_n_add_parse_tree(){
    int state=0;
    int col=4;

    for(int i=0; i<input.size();i++){

        string input_s=input.at(i);
        //checks if the input is in the map_keys which returns col
        //if not then its a symbol
        if(map_keys.contains(Pair<string,int>(input_s))){
            col=map_keys[input_s];
        }else{
            col=4;
        }

        //checks the state uses old state and col
        state=Machine[state][col];


        if(state==-1){
            //to get out of the for loop
            //input was wrong
//            cout<<"wrong input"<<endl;
            i=input.size();
        }

        //uses the state gotten from the machine
        switch(state){
        case 1: if(i==0){
            parse_tree.insert("command",input.at(i));
            }
            break;
        case 9: parse_tree.insert("command",input.at(i));
            break;
        case 14: parse_tree.insert("command",input.at(i));
            break;
        case 2:
        case 13:
            parse_tree.insert("fields/values",input_s);
            break;
        case 4:
        case 11:
            parse_tree.insert("table_name",input_s);
            break;
        case 5:
            parse_tree.insert("where","yes");
            break;
        case 6:
            parse_tree.insert("condition",input_s);
            break;
        case 7:
            parse_tree.insert("condition",input_s);
            break;
        case 8:
              parse_tree.insert("condition",input_s);
            break;
        default: //add if more col are added to table
            break;
        }

    }
    if(Machine[state][0]==1){
        //input was correct
    }else{
        parse_tree.empty();

    }
}

#endif // PARSE_H
