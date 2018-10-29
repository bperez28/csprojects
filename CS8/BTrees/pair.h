#ifndef PAIR_H
#define PAIR_H
#include <iostream>
using namespace std;


template <typename K, typename V>
struct Pair{
    K key;
    V value;

    Pair(const K& k=K(), const V& v=V()):key(k),value(v){

    }

    friend ostream& operator <<(ostream& outs, const Pair<K, V>& print_me){
        cout<<" Key: "<<print_me.key;
        cout<<" Value: "<<print_me.value;
        cout<<" ";

    }

    friend bool operator ==(const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        if(lhs.key==rhs.key){
            return true;
        }else{
            return false;
        }
    }
    friend bool operator !=(const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        if(lhs.key==rhs.key){
            return false;
        }else{
            return true;
        }
    }

    friend bool operator <(const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        if(lhs.key<rhs.key){
            return true;
        }else{
            return false;
        }
    }


    friend bool operator >(const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        if(lhs.key>rhs.key){
            return true;
        }else{
            return false;
        }
    }

    friend bool operator <=(const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        if(lhs.key<=rhs.key){
            return true;
        }else{
            return false;
        }
    }
    friend bool operator >=(const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        if(lhs.key>=rhs.key){
            return true;
        }else{
            return false;
        }
    }

    friend Pair<K, V> operator + (const Pair<K, V>& lhs, const Pair<K, V>& rhs){

    }
};
#endif // PAIR_H
