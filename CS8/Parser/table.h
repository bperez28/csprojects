#ifndef TABLE_H
#define TABLE_H
#include <ostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include "../BTrees/mmap.h"
#include "../BTrees/map.h"
#include "../binary_file_fun/file_record.h"
#include "../binary_file_fun/utilities.h"
#include "../binary_file_fun/consts.h"

using namespace std;
class Table{
public:
    Table(string table, vector<string> fields);
    Table(string table);
    void insert( vector<string> v);
    void select(vector<string> field_list, vector<string> condition);

private:
    //    long get_last_record(fstream& f);
    //    vector<string> input_record(string s);
    //    vector<string> fields_val;
    void make_op();
    fstream f;
    long recno=0;
    vector<MMap<string,long>> indices;
    string table_name;
    vector<string> field_rec;
    Map<string,int> op;

};

Table::Table(string table, vector<string> fields){
    string field=table+"_field.txt";
    table_name=table+".txt";
    bool debug=false;
    //create file
    //create indecices
    //create fieldlist
      file_record frec(recno);

    //prep the record to be written into file:
    for (int i = 0; i<fields.size(); i++){
        strcpy(frec.record[i+1], fields[i].c_str());
    }
    open_fileRW(f, field.c_str());
    //seek to the end of file:
    f.seekg (0, f.end);
    //write into the file and retrieve the record number of the
    //  record
    recno = frec.write(f);

    //close the file right away.
    f.close();

    open_fileRW(f, table_name.c_str());
    f.close();

    if(debug){
        //        read the record you just saved:
        open_fileRW(f, field.c_str());
        frec.read(f, recno);
        cout<<"reading the record from file:"<<endl;

        cout<<"recono: "<<setw(4)<<recno<<" "<<frec<<endl;
        cout<<"-----------------------------------"<<endl;

        cout<<"list of all records so far: "<<endl;
        for (int i= 0; i<=recno; i++){
            frec.read(f, i);
            cout<<"recono: "<<setw(4)<<i<<" "<<frec<<endl;
        }
        f.close();
    }




}

Table::Table(string table){
    string field_file=table+"_field.txt";
    table_name=table+".txt";

    recno=0;
    file_record frec(recno);
    open_fileRW(f, field_file.c_str());
    recno= frec.rec_no(f);
    f.close();

    open_fileRW(f, field_file.c_str());

    for (int i= 0; i<recno; i++){
        frec.read(f, i);
        for (int j=1; frec.record[j][0]!= NULL && j<MAX_RECORD_WIDTH; j++){

            field_rec.push_back(frec.record[j]);

        }

    }


    f.close();

    recno=0;
    file_record srec(recno);


    open_fileRW(f, table_name.c_str());
    recno= srec.rec_no(f);
    f.close();

    open_fileRW(f, table_name.c_str());

    for (long i= 0; i<=recno; i++){
        srec.read(f, i);
        for (int j=1; srec.record[j][0]!= NULL && j<MAX_RECORD_WIDTH; j++){
            //                        hold.push_back(srec.record[j]);
            MMap<string,long> hold;
            hold.insert(srec.record[j],i);
            indices.push_back(hold);

        }

    }

    f.close();




}

void Table::insert(vector<string> v){
    recno=0;
    bool debug=false;

    file_record frec(recno);

    //prep the record to be written into file:
    for (int i = 0; i<v.size(); i++){
        strcpy(frec.record[i+1], v[i].c_str());
    }

    open_fileRW(f, table_name.c_str());
    //seek to the end of file:
    f.seekg (0, f.end);

    //write into the file and retrieve the record number of the
    //  record
    recno = frec.write(f);

    //close the file right away.
    f.close();


    if(debug){
        //        read the record you just saved:
        open_fileRW(f, table_name.c_str());
        frec.read(f, recno);
        cout<<"reading the record from file:"<<endl;

        cout<<"recono: "<<setw(4)<<recno<<" "<<frec<<endl;
        cout<<"-----------------------------------"<<endl;

        cout<<"list of all records so far: "<<endl;
        for (int i= 0; i<=recno; i++){
            frec.read(f, i);
            cout<<"recono: "<<setw(4)<<i<<" "<<frec<<endl;
        }
        f.close();
    }


}

void Table::select(vector<string> field_list, vector<string> condition){


    if(field_list.at(0)=="*"){
        recno=0;
        file_record frec(recno);
        open_fileRW(f, table_name.c_str());
        frec.read(f, recno);
        recno=frec.rec_no(f);

        for (int i= 0; i<=recno; i++){
            frec.read(f, i);
            cout<<"recono: "<<setw(4)<<i<<" "<<frec<<endl;
        }
        f.close();

    }else{
    queue<string> q;
    stack<vector<long>> s;
    string and_or;
    make_op();

    for(int i=0; i<condition.size();i++){
        if(op.contains(condition.at(i))){
            q.push(condition.at(i));
            i++;
            q.push(condition.at(i));

            string hold=q.front();
            q.pop();
            string hold2=q.front();
            q.pop();

            q.push(hold);
            q.push(hold2);

        }else if(condition.at(i)=="and" || condition.at(i)=="or"){
           and_or=condition.at(i);
        }else{
            q.push(condition.at(i));
        }

    }



    while(!q.empty()){

        string hold1=q.front();
        q.pop();
        string hold2=q.front();
        q.pop();
        string hold3=q.front();
        q.pop();
      if(hold3=="=" || hold3=="!="){
//            s.push(indices[hold1].get(hold2));


        }else if(hold3==">"){
//           for(MMap<string,long>::Iterator it=indices[hold1].upper_bound(hold2);
//               it!=indices[hold1].end();++it){

//               s.push((*it).value_list);
//           }

        }else if(hold3=="<"){
//           for(MMap<string,long>::Iterator it=indices[hold1].begin();
//               it!=indices[hold1].upper_bound(hold2);++it){

//                s.push((*it).value_list);
//           }

        }else if(hold3==">="){
//           for(MMap<string,long>::Iterator it=indices[hold1].lower_bound(hold2);
//               it!=indices[hold1].end();++it){

//               s.push((*it).value_list);
//           }

        }else if(hold3=="<="){
//           for(MMap<string,long>::Iterator it=indices[hold1].begin();
//               it!=indices[hold1].upper_bound(hold2);++it){

//               s.push((*it).value_list);
//           }

        }
    }
//    if(and_or=="and"){

//        q.push(and_or);
//    }else if(and_or=="or"){

//    }





    //        file_record srec(recno);

    //        //read the record you just saved:
    //        open_fileRW(f, table_name.c_str());

    //        for (int i= 0; i<=recno; i++){

    //            srec.read(f, i);
    //            for (int j=1; srec.record[j][0]!= NULL && j<MAX_RECORD_WIDTH; j++){

    //                srec.record[j];

    //                cout<<srec.record[j];
    //                cout<<endl;
    //            }
    //        }
    //        f.close();

            cout<<"---- DONE -------"<<endl;

    }
}

void Table::make_op(){
    op.insert("=",0);
    op.insert("!=",1);
     op.insert(">=",2);
      op.insert("<=",3);
       op.insert("<",4);
        op.insert(">",5);

}


#endif // TABLE_H
