#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template<class T>
class Stack
{    
private:
    int Max_size=100;
    T *array;
    int index=0;
public:
    Stack();
    void push(T item);
    void pop();
    bool empty();
    void print();
    T top();

    template <class U>
    friend ostream& operator <<(ostream& cout, Stack<U>& q){
        for(int i=0; i<q.index; i++){
            cout<<"["<<q.array[i]<<"]"<<" ";
        }
    }
};

template<class T>
Stack<T>::Stack()
{
    array= new T[Max_size];
}

template<class T>
void Stack<T>::push(T item){
    //if undersize limit add item
    if(index<Max_size){
    array[index]=item;
    }
    else{
        //increase size of array
        Max_size=Max_size+Max_size/2;
        //create new array to copy old one in
        T *new_array;
        new_array= new T[Max_size];
        //copy old to new
        for(int i=0; i<=index;i++){
            new_array[i]=array[i];
        }
        //create new array from old
        array= new T[Max_size];
        for(int i=0; i<=index;i++){
           array[i]=new_array[i];
        }
        //add item
        array[index]=item;

    delete[] new_array;
    }
 index++;
}

template<class T>
void Stack<T>::pop(){
    //index must be greater than zero
    if(index>0){
    array[index-1]=NULL;
    index--;
    }else{
        //if user tries to go under zero index
        index=0;
         array[index]=NULL;
    }
}
template<class T>
bool Stack<T>::empty(){
    //checks if array is empty
    if(array[index-1]!=NULL){
        return 0;
    }
    return 1;
}

template<class T>
T Stack<T>::top(){
    //returns the next pop int
    if(array[index-1]!=NULL){
    return array[index-1];
    }
    return 0;
}

#endif // STACK_H
