#include <iostream>
#include <string>
#include "btree.h"
#include "array_functions.h"
#include "bplustree.h"
#include "map.h"
#include "pair.h"
#include "mmap.h"
#include "mpair.h"
#include <vector>

using namespace std;
int Random(int lo, int hi);
void test_iterator();
void test_bplustree_auto(int tree_size, int how_many, bool report);
bool test_bplustree_auto(int how_many, bool report);
void test_map();
void test_mmap();
void test_bplustree();
int main(int argc, char *argv[])
{
    cout <<endl<<endl<<endl<< "===============================" << endl<<endl<<endl<<endl;

    //------------------------------------------
    srand(time(0));
    //------------------------------------------

    test_bplustree();

//    test_bplustree_insert_random();
//    test_bplustree_remove();
//    test_bplustree_interactive();
//    test_bplustree_big_three();
//    test_bplustree_auto(1000,100,true);

    test_map();
    test_mmap();
//    test_map_interactive();

//    test_multimap();
//    test_multimap_interactive();
//    test_multimap_auto();

    //this works
//    test_iterator();
    cout <<endl<<endl<<endl<< "===============================" << endl;
    return 0;
}

void test_bplustree(){
    cout<<"-----------------------------BPlusTree_test------------------------"<<endl;

    BPlusTree<char> m;
    for(char c='a';c<='z';c++){
        m.insert(c);
    }

    cout<<m;
    for(char c='a';c<='z';c++){
        if(m.contains(c)){
            cout<<"map contains: ";
            cout<<m.get_existing(c)<<endl;
        }else{
            cout<<"map doesnt contains: "<<endl;
        }
    }



}

void test_map(){

    cout<<"-----------------------------test_map------------------------"<<endl;

    Map<char,int> m;
    int i=0;
    for(char c='a';c<='z';c++){
        m.insert(c,i);
        i++;
    }

    cout<<m;
        i=0;
        for(char c='a';c<='z';c++){
            if(m.contains(c)){
                cout<<"map contains: ";

                       cout<<m.get(c);
                          cout<<endl;
            }else{
                cout<<"map doesnt contains: "<<endl;
            }
            i++;
        }





}

void test_mmap(){
    cout<<"-----------------------------test_mmap------------------------"<<endl;

    MMap<char,int> m;
    int i=0;
    for(char c='a';c<='z';c++){
        m.insert(c,i);
        i++;
    }

    for(char c='a';c<='z';c++){
        m.insert(c,i);
        --i;
    }

    cout<<m;
        i=0;
        for(char c='a';c<='z';c++){
            if(m.contains(c)){
                cout<<"map contains: ";

                       cout<<m.get(c);
                          cout<<endl;
            }else{
                cout<<"map doesnt contains: "<<endl;
            }
            i++;
        }





}


void test_iterator(){
    const bool debug = false;
    BPlusTree<int> bpt;
    for (int i= 0; i<125; i++){
        bpt.insert(Random(0,100));
    }

    cout<<bpt;
    cout<<endl;

    cout<<"------------------------------------------------------------"<<endl;
    for(BPlusTree<int>::Iterator it = bpt.Begin();
                                    it!= bpt.End(); ++it){
        if (debug) it.print_Iterator();
        cout<<"["<<*it<<"] ";
        if (debug) cout<<endl;
    }

    cout<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"test ++ operator: "<<endl;
    BPlusTree<int>::Iterator it = bpt.Begin();
    cout<<"{"<<*(++it)<<"}"<<endl;
    cout<<"{"<<*it<<"}"<<endl;
    for (int i = 60; i<75; i++){
        it = bpt.find(i);
        if (!it.is_null())
            cout<<*it<<" was found."<<endl;
        else
            cout<<i<<" was not found"<<endl;
        }
    cout<<"===================================================================="<<endl;

}

void test_bplustree_auto(int tree_size, int how_many, bool report){
    bool verified = true;
    for (int i = 0; i< how_many; i++){
        if (report){
            cout<<"*********************************************************"<<endl;
            cout<<" T E S T:    "<<i<<endl;
            cout<<"*********************************************************"<<endl;
        }
        if (!test_bplustree_auto(tree_size, report)){
            cout<<"T E S T :   ["<<i<<"]    F A I L E D ! ! !"<<endl;
            verified = false;
            return;
        }

    }
    cout<<"**************************************************************************"<<endl;
    cout<<"**************************************************************************"<<endl;
    cout<<"             E N D     T E S T: "<<how_many<<" tests of "<<tree_size<<" items: ";
    cout<<(verified?"VERIFIED": "VERIFICATION FAILED")<<endl;
    cout<<"**************************************************************************"<<endl;
    cout<<"**************************************************************************"<<endl;

}

bool test_bplustree_auto(int how_many, bool report){
    const int MAX = 10000;
    assert(how_many < MAX);
    BPlusTree<int> bpt;
    int a[MAX];
    int original[MAX];
    int deleted_list[MAX];

    int original_size;
    int size;
    int deleted_size = 0;

    //fill a[ ]
    for (int i= 0; i< how_many; i++){
        a[i] = i;
    }
    //shuffle a[ ]: Put this in a function!
    for (int i = 0; i< how_many; i++){
        int from = Random(0, how_many-1);
        int to = Random(0, how_many -1);
        int temp = a[to];
        a[to] = a[from];
        a [from] = temp;
    }
    //copy  a[ ] -> original[ ]:
    copy_array(original, a, how_many,how_many);
    size = how_many;
    original_size = how_many;
    for (int i=0; i<size; i++){
        bpt.insert(a[i]);

    }
    if (report){
        cout<<"========================================================"<<endl;
        cout<<"  "<<endl;
        cout<<"========================================================"<<endl;
        cout<<bpt<<endl<<endl;
    }
    for (int i= 0; i<how_many; i++){
        int r = Random(0, how_many - i - 1);
        if (report){
            cout<<"========================================================"<<endl;
            cout<<bpt<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . "<<endl;
            cout<<"deleted: "; print_array(deleted_list, deleted_size);
            cout<<"   from: "; print_array(original, original_size);
            cout<<endl;
            cout<<"  REMOVING ["<<a[r]<<"]"<<endl;
            cout<<"========================================================"<<endl;
        }
        //this function is not implemented
//        bpt.remove(a[r]);


        delete_item(a, r, size, deleted_list[deleted_size++]);
        if (!bpt.is_valid()){
            cout<<setw(6)<<i<<" I N V A L I D   T R E E"<<endl;
            cout<<"Original Array: "; print_array(original, original_size);
            cout<<"Deleted Items : "; print_array(deleted_list, deleted_size);
            cout<<endl<<endl<<bpt<<endl<<endl;
            return false;
        }

    }
    if (report) cout<<" V A L I D    T R E E"<<endl;

    //changing these to see if github pickes it up
    return true;
}
int Random(int lo, int hi)
{
    int r = rand()%(hi-lo+1)+lo;

    return r;
}
