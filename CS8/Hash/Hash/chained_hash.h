#ifndef CHAINED_HASH_H
#define CHAINED_HASH_H
#include <cstdlib>
#include <iostream>
#include "../CS8/BTS/avl.h"
using namespace std;


template <class R>
class chained_hash
{

public:
    static const int CAPACITY = 811;
    chained_hash();
    void insert(const R& entry);
    //insert record if no match key
    //   if same key found replace it
    void remove(int key);
    //if record is in has remove it,
    //   not found leave alone
    bool is_present(int key) const;
    //if a matching key found return true
    // otherwise false
    void find(int key, bool& found,R& result);
    //if key is found value for found= true
    //and result changes to the record
    int size( ) const{ return used;}
    // return total value of records

    friend ostream& operator <<(ostream& outs, chained_hash<R>& print_me){
        for(int i=0; i<=CAPACITY-1;i++){
            cout<<"["<<i<<"]"<<" ";
            if(!print_me.data[i].rootisnull()){
            cout<<print_me.data[i];
            }
            cout<<endl;

        }


    }
    private:
    // MEMBER CONSTANTS -- These are used in the key field of special records. static const int NEVER_USED = -1;
    static const int PREVIOUSLY_USED = -2;
    static const int NEVER_USED = -1;
    // MEMBER VARIABLES
    avl<R> data[CAPACITY];
    int collision;
    int used;
    int _key;
    // HELPER FUNCTIONS
    int hash(int key) const;
    //hashes a key to an array index
    int next_index(int index) const;
    //next_index usually returns i + 1
    //except if i is the end of the array
    void find_index(int key, bool& found, int& index) const;
    //goes through the array if key is found set found=true
    // than set the index to where its placed in the array
    bool never_used(int index) const;
    //if the index has never been used
    bool is_vacant(int index) const;
    //if the space is not currently used
};


template <class R>
chained_hash<R>::chained_hash()
{
    for(int i=0; i<=CAPACITY-1; i++){
        avl<R> a;
        data[i]=a;

    }
    used=0;

}

template <class R>
void chained_hash<R>::insert(const R& entry){
    //insert record if no match key
    //   if same key found replace it
    int key;
    key>>entry;
    int index=hash(key);

    bool inserted=false;
    while(!inserted){
    if(index!=CAPACITY-1){
        data[index].insert(entry);
        used++;
        inserted=true;

    }else{
        index=next_index(index);
    }
    }


}

template <class R>
void chained_hash<R>::remove(int key){
    //if record is in has remove it,
    //   not found leave alone
    int index=hash(key);
    if(data[index].erase(key)){
        used--;

    }
}

template <class R>
bool chained_hash<R>::is_present(int key) const{
    //if a matching key found return true
    // otherwise false
    int i;
    bool found;
    find_index(key,found,i);
    return found;
}

template <class R>
void chained_hash<R>::find(int key, bool& found,R& result){
    //if key is found value for found= true
    //and result changes to the record
    int index;
    find_index(key,found,index);
    found=data[index].search(key);
    if(found){
//        result>>data[index];
    }else{
//        cout<<"was't found"<<endl;
    }


}
template <class R>
int  chained_hash<R>::hash(int key) const{
    //hashes a key to an array index
    return (key%CAPACITY);
}
template <class R>
int chained_hash<R>::next_index(int index) const{
    //next_index usually returns i + 1
    //except if i is the end of the array
    return ((index+1)%CAPACITY);
}
template <class R>
void  chained_hash<R>::find_index(int key, bool& found, int &index) const{
    //goes through the array if key is found set found=true
    // than set the index to where its placed in the array
    index=hash(key);
    found =true;
}
template <class R>
bool  chained_hash<R>::never_used(int index) const{
    //if the index has never been used
    if(data[index].rootisnull()){
        return true;
    }else{
        return false;
    }
}
template <class R>
bool  chained_hash<R>::is_vacant(int index) const{
    //if the space is not currently used
    if(data[index]==R(NEVER_USED) || data[index]==R(PREVIOUSLY_USED) ){
        return true;
    }else{
        return false;
    }
}

#endif // CHAINED_HASH_H
