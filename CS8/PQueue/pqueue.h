#ifndef PQUEUE_H
#define PQUEUE_H
#include "heap.h"
#include <iostream>
using namespace std;
template <typename T>
struct info{
    T item;
    int priority;

    info();
    info(T i, int p){
        item=i;
        priority=p;
    }

//    friend ostream& operator <<(ostream& outs, const info<T>& print_me){
//        out<<print_me.priority<<":"<<print_me.item<<endl;
//    }

    friend bool operator <(const info<T>& lhs, const info<T>& rhs){
        if(lhs.priority<rhs.priority || lhs.priority==rhs.priority ){
            return true;
        }else{
            return false;
        }
    }
};
template <typename T>
class PQueue
{
public:
    PQueue();

    bool insert(const T& value, int p){
//        info<T> i(value,p);

    }

    T Pop();

    bool is_empty() const;
    int size() const;
    void print_tree() const;
    friend ostream& operator <<(ostream& outs, const PQueue<T>& print_me);

private:
    Heap<info<T> > heap;

};

#endif // PQUEUE_H
