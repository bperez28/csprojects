#ifndef MMAP_H
#define MMAP_H
#include"array_functions.h"
#include "assert.h"
#include "bplustree.h"
#include "mpair.h"
#include "vector"
#include <iostream>
#include <iomanip>
using namespace std;
template <typename K, typename V>
class MMap
{
public:
    typedef BPlusTree<MPair<K, V> > map_base;
    class Iterator{
    public:
        friend class MMap;
        Iterator(typename map_base::Iterator it){
            _it=it;
        }

//        Iterator operator ++(int unused){
//            Iterator hold;
//            hold=_it.it;
//            _it.it++;
//            return hold;

//        }

        Iterator operator ++(){
            ++_it.key_ptr;
            if(_it.key_ptr >= _it.it->data_count){
                _it.key_ptr=0;
                _it=_it.it->next;

            }
        }

        MPair<K, V> operator *(){
            assert(_it.key_ptr<_it.it->data_count);
            return _it.it->data[_it.key_ptr];
        }

        friend bool operator ==(const Iterator& lhs, const Iterator& rhs){
            return lhs._it==rhs._it;
        }

        friend bool operator !=(const Iterator& lhs, const Iterator& rhs){
             return !(lhs._it==rhs._it);
        }

    private:
        typename map_base::Iterator _it;
    };

    MMap();

//  Iterators
    Iterator begin();
    Iterator end();

//  Capacity
    int size() const;
    bool empty() const;

//  Element Access
    const vector<V>& operator[](const K& key) const;
    vector<V>& operator[](const K& key);
    vector<V>& operator+=(const V& val);

//  Modifiers
    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();

//  Operations:
    bool contains(const K& key) ;
    vector<V> &get(const K& key);

    Iterator find(const K& key);
    int count(const K& key);
    // I have not writtent hese yet, but we will need them:
    //    int count(const K& key);
        Iterator lower_bound(const K& key);
        Iterator upper_bound(const K& key);
    //    equal_range:



    bool is_valid();

    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me){
        cout<<print_me.mmap;

    }

private:
    BPlusTree<MPair<K, V> > mmap;
};


template <typename K, typename V>
MMap<K,V>::MMap(){
    mmap.dups_ok=true;

}

//  Iterators
template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::begin(){
       return mmap.Begin();
}
template <typename K, typename V>
typename MMap<K,V>::Iterator  MMap<K,V>::end(){
   return mmap.End();
}

//  Capacity
template <typename K, typename V>
int MMap<K,V>::size() const{
    return mmap.size();
}
template <typename K, typename V>
bool MMap<K,V>::empty() const{
        return mmap.empty();
}

//  Element Access
template <typename K, typename V>
const vector<V>& MMap<K,V>::operator[](const K& key) const{
        return mmap.get(key).value_list;
}
template <typename K, typename V>
vector<V>& MMap<K,V>::operator[](const K& key){
        return mmap.get(key).value_list;

}

//  Modifiers
template <typename K, typename V>
void MMap<K,V>::insert(const K& k, const V& v){
    if(!mmap.contains(MPair<K,V>(k,v))){
    mmap.insert(MPair<K,V>(k,v));
    }else{
   mmap.get_existing(MPair<K,V>(k)).value_list.push_back(v);
    }

}

template <typename K, typename V>
void MMap<K,V>::erase(const K& key){
        mmap.remove(key);
}

template <typename K, typename V>
void MMap<K,V>::clear(){
    mmap.clear_tree();
}

//  Operations:
template <typename K, typename V>
bool MMap<K,V>::contains(const K& key){
        return mmap.contains(key);
}
template <typename K, typename V>
vector<V>& MMap<K,V>::get(const K& key){

  return mmap.get(key).value_list;

}

template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::find(const K& key){
        return mmap.find(key);
}
template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::lower_bound(const K& key){

    for(typename BPlusTree< MPair<K,V> >::Iterator it=mmap.Begin(); it!=mmap.End();++it){

        if(it.it->data[it.key_ptr]==MPair<K,V>(key)){

            return Iterator(it.it);
        }
    }
    return Iterator(NULL);
}
template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::upper_bound(const K& key){
    for(typename BPlusTree< MPair<K,V> >::Iterator it=mmap.Begin(); it!=mmap.End();++it){
        if(it.it->data[it.key_ptr]==MPair<K,V>(key)){
            return Iterator(++it.it);
        }

}
    return Iterator(NULL);
}

template <typename K, typename V>
int MMap<K,V>::count(const K& key){

}

// I have not writtent hese yet, but we will need them:
//    int count(const K& key);
//    lower_bound
//    upper_bound
//    equal_range:


template <typename K, typename V>
bool MMap<K,V>::is_valid(){
    return mmap.is_valid();
}


#endif // MMAP_H
