#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "assert.h"
using namespace std;

template<class T>
struct node{
    node<T>* next;
    T _item;
    node(T item){
        _item=item;
    }
    friend ostream& operator <<(ostream& outs, node<T>* t){
        outs<<t->_item<<endl;
        outs<<t->next->_item<<endl;



        return outs;

    }
};

template <class ITEM_TYPE>
class List
{
public:

    class Iterator{
    public:
        friend class List;                              //give access to list to access _ptr
        Iterator(){
            //default ctor

        }
        Iterator(node<ITEM_TYPE>* p=NULL):_ptr(p){}
            //Point Iterator to where p is pointing to


        operator bool(){
            //casting operator: true if _ptr not NULL
            //      this turned out to be a pain!
            if(_ptr==NULL){
                return false;
            }else{
                return true;
            }

        }


        ITEM_TYPE& operator *(){
            //dereference operator
            assert(_ptr);
            return *_ptr;

        }
        ITEM_TYPE* operator ->(){
            //member access operator
            return *_ptr->next;
        }

        bool is_null(){
            //true if _ptr is NULL
            if(_ptr==NULL){
                return true;
            }else{
                return false;
            }

        }

        friend bool operator !=(const Iterator& left,
                                const Iterator& right){
            //true if left != right
            if(left._ptr!=right._ptr){
                return true;
            }else{
                return false;
            }

        }

        friend bool operator ==(const Iterator& left,
                                const Iterator& right){
            //true if left == right
        if(left._ptr==right._ptr){
            return true;
        }else{
            return false;
        }
        }

        Iterator& operator++(Iterator& it,
                             int unused){
            //member operator: ++it; or ++it = new_value
       Iterator temp;
       temp= it;
       it._ptr++;
       return hold;
        }

        friend Iterator operator++(Iterator& it,
                                   int unused){
            //friend operator: it++
        _ptr++;
        return *this-;
        }

    private:
        node<ITEM_TYPE>* _ptr;                          //pointer being encapsulated
    };

    List(){
        //CTOR

    }
    //BIG 3:
    ~List(){
        *_head_ptr=NULL;
        *_head_ptr->next=NULL;

    }

    List(const List<ITEM_TYPE> &copyThis){
        if(_head_ptr!=copyThis._head_ptr){
            delete _head_ptr;
            *_head_ptr=copyThis._head_ptr;
        }

    }

    List& operator =(const List& RHS){
        this->size=RHS.size;


    }

    Iterator InsertHead(ITEM_TYPE i){
        //insert at the head of list
           node<ITEM_TYPE>* hold= _head_ptr;
           _head_ptr->_item=i;
           _head_ptr->next=hold;
           delete hold;


    }
    Iterator InsertAfter(ITEM_TYPE i, Iterator *iMarker){
        //insert after marker


    }
    Iterator InsertBefore(ITEM_TYPE i, Iterator iMarker){
        //insert before marker

    }
    Iterator InsertSorted(ITEM_TYPE i){
        //insert in a sorted list

    }

    ITEM_TYPE Delete(List<ITEM_TYPE>::Iterator iMarker){
        //delete node pointed to by marker

    }
    void Print() const{


    }
    Iterator Search(const ITEM_TYPE &key){
        //return Iterator to node [key]

    }
    Iterator Prev(Iterator iMarker){
        //previous node to marker

    }

    ITEM_TYPE& operator[](int index){
        //return item at position index
       return (_head_ptr+index);
    }
    Iterator Begin() const{

        //Iterator to the head node
        Iterator b(_head_ptr);
        return b;
    }
    Iterator End() const{

        //Iterator to NULL
        Iterator e(_head_ptr+size);
        return e;
    }
    Iterator LastNode() const{
        //Iterator to the last node
        Iterator t(_head_ptr+size-1);
        return t;

    }
    template <class U>                                          //Note the template arg U
    friend ostream& operator <<(ostream& outs, const List<U>& l){


    }

private:
    node<ITEM_TYPE>* _head_ptr;
    int size;
};


#endif // LIST_H
