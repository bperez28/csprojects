#include <iostream>
#include "../BTree/array_functions.h"
#include "assert.h"
using namespace std;

template <class T>
class List{
public:
    class Iterator{
        //the nested class
    public:
        friend class List;                  //this will allow List
        //  to access the private
        //  members of Iterator
        Iterator next()                     //return an iterator to the
        {                                   //  next location in the list
            return Iterator(_ptr + 1);
        }


        Iterator(T* p = NULL):_ptr(p){}     //ctor
        T& operator *(){                    //dereference oprator
            assert(_ptr);
            return *_ptr;
        }

        friend Iterator operator ++(Iterator& it,       //it++
                                    int unused){
            Iterator hold;
            hold = it;
            it._ptr++;
            return hold;
        }
        Iterator& operator ++(){                        //++it
            _ptr++;
            return *this;
        }


        friend bool operator !=(const Iterator& left,   //it != it
                                const Iterator& right){
            return left._ptr != right._ptr;
        }


    private:
        T* _ptr;                    //pointer being
        //  encapsulated
    };

    List(T* array, int size);
    //List ctor


    //---------------------------- big three -----------------------------------
    ~List();

    List(const List& other);

    List& operator =(const List& RHS);

    //---------------------------------------------------------------------------
    Iterator Begin() const;
    //an iterator to the start of List

    Iterator Find(const T& entry) const;

    Iterator End() const;
    //an iterator to the end of List


private:
    T* _a_list;                     //the List raw data
    int _how_many;                  //size of List
};
template <class T>
List<T>::List(T *array, int size){
    _a_list = copy_array(array, size);
    _how_many = size;

}
//---- BIG THREE --------------------------------
template <class T>
List<T>::~List(){
    destroy_array(_a_list);
}

template <class T>
List<T>::List(const List& other){
    _a_list = copy_array(other._a_list, other._how_many);
    _how_many = other._how_many;

}

template <class T>
List<T>& List<T>::operator =(const List& RHS){
    if (this == &RHS) return *this;
    destroy_array(_a_list);
    _a_list = copy_array(RHS._a_list, RHS._how_many);
    _how_many = RHS._how_many;
}
//-----------------------------------------------------


template <class T>
typename List<T>::Iterator List<T>::Begin() const{
    //C++ requires you to use the keyword typename when referring to the Iterator outside
    //      the class declaration
    return Iterator(_a_list);
}

template <class T>
typename List<T>::Iterator List<T>::End() const{
    //probably a terrible idea!
    return Iterator(_a_list+_how_many);
}

template <class T>
typename List<T>::Iterator List<T>::Find(const T& entry) const{

    List<T>::Iterator it;             //a List Itertor object
    for (it=this->Begin();
         it!=this->End();
         it++){                         //postfix ++
        //looping through all the elements of List using the Iterator
        if(*it==entry){
            return it;
        }
    }

    return it;


}






int main(int argc, char *argv[])
{
    cout <<endl<<endl<< "=======================" << endl<<endl;
    cout<<endl<<endl<<"Testing a list of ints:"<<endl;
    int a[] = {1,1,3,5,8,13};           //an array! (sorry about this!)
    List<int> list(a, 6);               //instantiate a List object
    List<int>::Iterator it;             //a List Itertor object
    for (it=list.Begin();
         it!=list.End();
         it++){                         //postfix ++
        //looping through all the elements of List using the Iterator
        cout<<*it<<"|";
    }


    //delete it;      //cannot be done.
    //delete it._ptr; //cannot be done.
    cout<<endl<<endl<<"Testing a list of strings:"<<endl;
    //
    string s[] = {string("Curly"), string("Moe"), string("Larry")};
    List<string> slist(s, 3);
    List<string>::Iterator sit;           //a List Itertor object
    for (sit=slist.Begin();
         sit!=slist.End();
         ++sit){

        //prefix ++
        //looping through all the elements of List using the Iterator
        cout<<*sit<<"|";
    }
    cout<<endl<<"Find:";
    cout<<*slist.Find("Curly");


    cout<<endl;
    cout <<endl<<endl<< "=======================" << endl<<endl;
    return 0;
}
