#ifndef RECORD_H
#define RECORD_H
#include <iostream>
using namespace std;
struct record
{
    int _key;
    double _value;

    record(int k=0, double v=0):_key(k), _value(v){}
    friend bool operator ==(const record& left, const record& right){

        if(left._key==right._key){
            return true;
        }else{
            return false;
        }
    }
    friend ostream& operator <<(ostream& outs, const record& print_me){
        if((print_me._key>=0 && print_me._value>=0)){
        cout<<print_me._key;
        cout<<" : ";
        cout<<print_me._value;
        }else if(print_me._key==-2 && print_me._value==-2){
            cout<<"- - - - - - - -";
        }
    }
    friend bool operator <(const record& left, const record& right){
        if(left._key<right._key){
            return true;
        }else{
            return false;
        }
    }

    friend ostream& operator >>(int& key,  const record& right){
        key=right._key;
    }
    friend ostream& operator >>( record& left,const int& set){
       left._key=set;
       left._value=set;
    }
    friend ostream& operator >>( record& left,record& right){
       left._key=right._key;
       left._value=right._value;
    }

};
#endif // RECORD_H
