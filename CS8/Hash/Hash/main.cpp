#include <iostream>
#include "record.h"
#include "open_hash.h"
#include "double_hash.h"
#include "chained_hash.h"
#include "random.h"
using namespace std;

template<class Record>
void test_hash_table_interactive(open_hash<Record> open,string str);
template<class Record>
void test_hash_table_interactive(chained_hash<Record> chained,string str);
template<class HASH_TABLE>
void test_hash_table_random(HASH_TABLE& h_table, long how_many, string hash_type);
template <class T>
void print_array(T* a, long how_many);

template <class T>
bool exists_in_array(T* a, long how_many, const T& item);
int main(int argc, char *argv[])
{

    cout<<endl<<endl<<endl<<"----------------------"<<endl<<endl<<endl;
    const bool RANDOM_CHAINED = false;
    const bool RANDOM_OPEN = true;
    const bool INTERACTIVE_OPEN = false;
    const bool INTERACTIVE_CHAINED = false;

    if (INTERACTIVE_OPEN){
        cout<<"-------  INTERACTIVE TESTS ---------------------------"<<endl;
        open_hash<record> open;
        test_hash_table_interactive(open, "open_hash_table" );
    }

    if (INTERACTIVE_CHAINED){
        cout<<"-------  INTERACTIVE TESTS ---------------------------"<<endl;
        chained_hash<record> chained;
        test_hash_table_interactive(chained, "chained_hash_table" );
    }

    if (RANDOM_CHAINED){
        //----------- RANDOM TEST ------------------------------
        //. . . . . .  Chained Hash Table . . . . . . . . . . .;
        chained_hash<record> c_table;
        test_hash_table_random(c_table, 2500, "chained_hash_table<record>");
        cout<<c_table<<endl;
    }

    if (RANDOM_OPEN){
        //----------- RANDOM TEST ------------------------------
        //. . . . . .  Simple Hash Table . . . . . . . . . . .;
        open_hash<record> h_table;
        test_hash_table_random(h_table, 500, "hash_table<record>");
        cout<<h_table<<endl;
    }

    cout<<endl<<endl<<endl<<"---------------------------------"<<endl;

}


template<class Record>
void test_hash_table_interactive(open_hash<Record> open,string str){
    char c;
    int key;
    char ran;
    int value;
    bool found=true;
    record rec;

    while(c!='x' || c!='X'){
        cout<<"[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :";
        cin>>c;
        switch(c){
        case 's':
        case 'S': cout<<endl<<"size: "<<open.size()<<endl;
            break;
        case 'i':
        case 'I': cin>>key>>ran>>value;
            open.insert(record(key,value));
            cout<<">>"<<key<<":"<<value<<" has been inserted"<<endl;
            break;
        case 'r':
        case 'R': key= rand() %10000;
            value=rand() %10000;
            open.insert(record(key,value));
            cout<<">>"<<key<<":"<<value<<" has been inserted"<<endl;
            break;
        case 'd':
        case 'D': cin>>key;
            open.remove(key);
            cout<<">> "<<key<<" has been removed"<<endl;
            break;
        case 'f':
        case 'F': cin>>key;
            open.find(key,found,rec);
            if(found){
                cout<<">>"<<rec;
                cout<<endl;
            }else{
                cout<<key<<" was not found"<<endl;
            }
            break;
        case '?': cin>>key;
            open.find(key,found,rec);
            if(found){
                cout<<"exists"<<endl;
            }else{
                cout<<key<<" doesnt exists"<<endl;
            }
            break;
        case 'x':
        case 'X':   cout<<"DONE."<<endl;
            break;
        default:
            cout<<"wrong input"<<endl;
            break;


        }
        cout<<open;
    }
}

template<class Record>
void test_hash_table_interactive(chained_hash<Record> chained,string str){
    char c;
    int key;
    char ran;
    int value;
    bool found=true;
    record rec;

    while(c!='x' || c!='X'){
        cout<<"[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :";
        cin>>c;
        switch(c){
        case 's':
        case 'S': cout<<endl<<"size: "<<chained.size()<<endl;
            break;
        case 'i':
        case 'I': cin>>key>>ran>>value;
            chained.insert(record(key,value));
            cout<<">>"<<key<<":"<<value<<" has been inserted"<<endl;
            break;
        case 'r':
        case 'R': key= rand() %10000;
            value=rand() %10000;
            chained.insert(record(key,value));
            cout<<">>"<<key<<":"<<value<<" has been inserted"<<endl;
            break;
        case 'd':
        case 'D': cin>>key;
            chained.remove(key);
            cout<<">> "<<key<<" has been removed"<<endl;
            break;
        case 'f':
        case 'F': cin>>key;
            chained.find(key,found,rec);
            if(found){
                cout<<">>"<<rec;
                cout<<endl;
            }else{
                cout<<key<<" was not found"<<endl;
            }
            break;
        case '?': cin>>key;
            chained.find(key,found,rec);
            if(found){
                cout<<"exists"<<endl;
            }else{
                cout<<key<<" doesnt exists"<<endl;
            }
            break;
        case 'x':
        case 'X':   cout<<"DONE."<<endl;
            break;
        default:
            cout<<"wrong input"<<endl;
            break;


        }
        cout<<chained;
    }
}

template<class HASH_TABLE>
void test_hash_table_random(HASH_TABLE& h_table, long how_many, string hash_type){
//#undef INTERACTIVE_TEST //sets the table size to a 811
    const bool debug = false;
    const bool TMI = false;
     bool found=true;
    const long MAX_KEY_SIZE = 10000;
    record* a = new record[how_many];
    Random r;
    cout<<"********************************************************************************"<<endl;
    cout<<"                 R A N D O M   H A S H   T E S T: "<<hash_type<<endl;
    cout<<"********************************************************************************"<<endl;

    for (int i=0; i<how_many; i++){
        a[i] = record(r.GetNext(0,MAX_KEY_SIZE), r.GetNext(0, MAX_KEY_SIZE)*1.0);
        if (debug) cout<<i<<":"<<a[i]<<" was inserted "<<endl;
        h_table.insert(a[i]);
    }
    cout<<"---- ["<<how_many<<"] keys inserted."<<endl;



    if (debug) print_array(a, how_many);
    record result;

    long found_count = 0;
    long not_found_count = 0;
    cout<<endl<<endl<<"- - - - - - - - - Search for existing keys ----------------"<<endl;
    cout<<"Search for existing keys: "<<how_many/2<<" keys to be tested: "<<endl;
    for (int i= 0;i<how_many/2; i++){
        int key = a[r.GetNext(0, how_many-1)]._key;
        h_table.find(key,found,result);
        if (found){
            if (TMI) cout<<result<<" WAS FOUND."<<endl;;
            found_count++;
        }
        else{
            if (TMI) cout<<endl<<endl<<"Existing Key ["<<key<<"] WAS NOT FOUND ****** ERROR ******"<<endl;
            not_found_count ++;
        }
    }


    if (not_found_count >0)
        cout<<"EXISTING KEYS   LOOKUP      V E R I F I C A T I O N   F A I L E D!!"<<endl;
    else
        cout<<"EXISTING KEYS LOOKUP: VERIFID. EXISTING KEYS EXAMINED: "<<found_count<<endl;


    cout<<endl<<endl<<"- - - - - - - - - Search for non-existent keys ----------------"<<endl;
    not_found_count = 0;
    found_count = 0;

    cout<<"Search for nonexistent keys: "<<how_many/2<<" keys to be tested: "<<endl;

    for (int i=0; i<how_many/2; i++){
        int key;
        record key_record;

        do{
            key_record = record(r.GetNext(0, MAX_KEY_SIZE-1), 0.0);
        }while (exists_in_array(a, how_many, key_record));
            h_table.find(key_record._key,found, result);
        if (found){
            if(TMI){
                cout<<endl<<endl<<key_record._key<<" NONEXISTENT KEYS LOOKUP VERIFICATION F A I L E D!!  ******"<<endl;
                cout<<"            result: "<<result<<endl;
            }
            found_count ++;
        }
        else{
            if (TMI) cout<<"NONEXISTENT KEY "<<key_record._key<<" WAS NOT FOUND: VERIFIED."<<endl;
            not_found_count ++;
        }
    }
    if (found_count >0)
        cout<<"NONEXISTENT KEYS LOOKUP      V E R I F I C A T I O N   F A I L E D!!"<<endl;
    else
        cout<<"NONEXISTENT KEYS LOOKUP: VERIFID. NONEXISTENT KEYS EXAMINED: "<<not_found_count<<endl;
    cout<<endl<<"------------------ END RANDOM TEST ----------------------"<<endl;

}
template <class T>
void print_array(T* a, long how_many){
    cout<<"-------- PRINTING ARRAY ----------------"<<endl;
    for (int i = 0; i<how_many; i++){
        cout<<"["<<setw(4)<<setfill('0')<<i<<"]: "<<a[i]<<endl;
    }
}
template <class T>
bool exists_in_array(T* a, long how_many, const T& item){
    const bool debug = false;
    int i;
    for (i=0; i< how_many; i++){
        if (a[i] == item){
            if(debug) cout<<"exists_in_array("<<item<<"): returning TRUE: "<<a[i]<<endl;
            return true;
        }
    }
    if (debug) cout<<"exists_in_array("<<item<<"): returning FALSE. searched "<<i<<"rows."<<endl;
    return false;
}

