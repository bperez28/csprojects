#ifndef MAP_H
#define MAP_H
#include <iostream>
#include"array_functions.h"
#include "assert.h"
#include "bplustree.h"
#include "pair.h"
#include <iomanip>
using namespace std;

template <typename K, typename V>
class Map
{
public:
    typedef BPlusTree<Pair<K, V> > map_base;
    class Iterator{
    public:
        friend class Map;
        Iterator(typename map_base::Iterator it){
            _it=it;
        }

        Iterator operator ++(int unused){
            Iterator hold;
            hold=_it.it;
            _it.it++;
            return hold;
        }

        Iterator operator ++(){
            ++_it.key_ptr;
            if(_it.key_ptr >= _it.it->data_count){
                _it.key_ptr=0;
                _it=_it.it->next;

            }
        }

        Pair<K, V> operator *(){
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

    Map();
    //  Iterators
    Iterator begin();
    Iterator end();

    //  Capacity
    int size() const;
    bool empty() const;

    //  Element Access
    V& operator[](const K& key);
    V& at(const K& key);
    const V& at(const K& key) const;


    //  Modifiers
    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();
    V& get(const K& key);

    //  Operations:
    Iterator find(const K& key);
    Iterator lower_bound(const K& key);
    Iterator upper_bound(const K& key);
    bool contains(const Pair<K, V>& target) ;

    // I have not writtent hese yet, but we will need them:
    //    int count(const K& key);
    //    lower_bound
    //    upper_bound
    //    equal_range:

    bool is_valid(){return map.is_valid();}

    friend ostream& operator<<(ostream& outs, const Map<K, V>& print_me){
        cout<<print_me.map;
        cout<<endl;
    }
private:
    int key_count;
    BPlusTree<Pair<K,V>> map;
};



template <typename K, typename V>
Map<K,V>::Map(){

}

//  Iterators
template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::begin(){
    return map.Begin();
}

template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::end(){
    return map.End();
}

//  Capacity
template <typename K, typename V>
int Map<K,V>::size() const{
    return map.size();
}
template <typename K, typename V>
bool Map<K,V>::empty() const{
    return map.empty();
}

//  Element Access
template <typename K, typename V>
V& Map<K,V>::operator[](const K& key){

         return map.get(key).value;

}

template <typename K, typename V>
V& Map<K,V>::at(const K& key){

}

template <typename K, typename V>
const V& Map<K,V>::at(const K& key) const{

}


//  Modifiers
template <typename K, typename V>
void Map<K,V>::insert(const K& k, const V& v){

    map.insert(Pair<K,V>(k,v));
}

template <typename K, typename V>
void Map<K,V>::erase(const K& key){
    map.remove(key);
}

template <typename K, typename V>
void Map<K,V>::clear(){
    map.clear_tree();
}

template <typename K, typename V>
V& Map<K,V>::get(const K& key){
  return map.get(Pair<K,V>(key)).value;
}

//  Operations:
template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::find(const K& key){
    return map.find(key);
}
template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::lower_bound(const K& key){

    for(typename BPlusTree< Pair<K,V> >::Iterator it=map.Begin(); it!=map.End();++it){

        if(it.it->data[it.key_ptr]==Pair<K,V>(key)){

            return Iterator(it.it);
        }
    }
    return Iterator(NULL);
}
template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::upper_bound(const K& key){
    for(typename BPlusTree< Pair<K,V> >::Iterator it=map.Begin(); it!=map.End();++it){
        if(it.it->data[it.key_ptr]==Pair<K,V>(key)){
            return Iterator(++it.it);
        }

}
    return Iterator(NULL);
}


template <typename K, typename V>
bool Map<K,V>::contains(const Pair<K, V>& target){

     bool contains =  map.contains(target);
     //this is a way to print true and false
//     cout<<(contains ?"map contains. true":"map contains.false")<<endl;
     return contains;


}

// I have not writtent hese yet, but we will need them:
//    int count(const K& key);
//    lower_bound
//    upper_bound
//    equal_range:


#endif // MAP_H
