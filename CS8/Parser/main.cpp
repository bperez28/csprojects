#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
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
#include "../Parser/sql.h"
using namespace std;
MMap<string, long> get_word_indices(char* file_name);

int main(int argc, char *argv[])
{
        string s;
//       s=" make table employee fields  last, 		first, 			dep,  		salary, 	year";

    //    s="insert into employee values Blow, JoAnn,			Physics, 	200000, 	2016";

//        s="insert into student values bo, yang, 28";
    //    s="select fname, lname from student where lname=perez";
        s="make table student fields fname, lname, age";

    SQL sq("_!batch_file.batch");


//    Parse p(s);


//    if(p.get_parse_tree()["command"].at(0)=="make"){
//        Table t(p.get_parse_tree()["table_name"].at(0),p.get_parse_tree()["fields/values"]);

//    }else if(p.get_parse_tree()["command"].at(0)=="insert"){
//        Table t(p.get_parse_tree()["table_name"].at(0));
//        t.insert(p.get_parse_tree()["fields/values"]);

//    }else if(p.get_parse_tree()["command"].at(0)=="select"){
//         Table t(p.get_parse_tree()["table_name"].at(0));
//         t.select(p.get_parse_tree()["fields/values"],p.get_parse_tree()["condition"]);


//    }else{
//        cout<<"doesnt contain"<<endl;
//    }

//    cout<<"============================end_of_parse_class=============================="<<endl;





//    MMap<string, long> word_indices;
//        word_indices = get_word_indices("solitude.txt");
//        cout<<endl<<endl<<endl;

//        //list all nodes of the index mmap:
//        for (MMap<string, long>::Iterator it = word_indices.begin();
//             it != word_indices.end(); ++it){
//            cout<<*it<<endl;
//        }


//        cout<<endl<<endl<<endl;
//        cout<<"---------------------------------------------------"<<endl;
//        string this_word = "ice";
//        cout<<"---------------------------------------------------"<<endl;
//        cout<<"Indices of \""<<this_word<<"\""<<endl;
//        //list indices of this_word:
//        if (word_indices.contains(this_word)){
//            cout<<this_word<<": "<<word_indices[this_word]<<endl;
//        }
//        cout<<endl<<endl<<endl;

//        cout<<"---------------------------------------------------"<<endl;
//        string from = "ask";
//        string to = "asker";
//        //list from .. to:
//        cout<<"listing indices from \""<<from<<"\" to \""<<to<<"\""<<endl;
//        cout<<"---------------------------------------------------"<<endl;
//        for (MMap<string, long>::Iterator it =
//                    word_indices.lower_bound(from);
//             it != word_indices.upper_bound(to) &&
//             it != word_indices.end(); ++it){
//            cout<<*it<<endl;
//        }

        cout <<endl<<endl<<endl<< "========== E N D  ====================" << endl;
        return 0;





}

MMap<string, long> get_word_indices(char* file_name){
    const bool debug = true;
    MMap<string, long> word_indices;
    FTokenizer ftk("solitude.txt");
    Token t;
    long count = 0;

    ftk >> t;
    while (ftk.more()){
        //only the "words"
        if (t.type_string() == "Alpha"){
            string s;

            s = t.Token_str();
            word_indices[s] += count;
            count++;
            if (debug)
                cout<<"|"<<s<<"|"<<endl;
        }
        ftk >> t;
    }
    return word_indices;
}

