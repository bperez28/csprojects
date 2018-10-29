#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template<class T>
class Queue
{
 private:
    int Max_size=100;
    T *array;


public:
     int index=0;
    Queue();
    void push(T item);
    void pop();
    bool empty();
    string get_object_as_str(int index);
    int get_index();
    void print();
    T top();

    template <class U>
    friend ostream& operator <<(ostream& outs, Queue<U>& q){
        for(int i=0; i<q.get_index(); i++){
            cout<<"["<<q.array[i]<<"]"<<" ";
        }
    }
};
template<class T>
Queue<T>::Queue()
{
    array= new T[Max_size];
}
template<class T>
string Queue<T>::get_object_as_str(int index){
    string str;
    str= ""+array[index];
    return str;
}

template<class T>
void Queue<T>::push(T item){
    //index must be smaller than array size
    if(index<Max_size){
    array[index]=item;
    }
    else{
    //if not we increase the size by making a new array
        Max_size=Max_size+Max_size/2;
        //new array to store old one
        T *new_array;
        new_array= new T[Max_size];
        //copying the old array
        for(int i=0; i<=index;i++){
            new_array[i]=array[i];
        }
        //creating a new array
        array= new T[Max_size];
        for(int i=0; i<=index;i++){
           array[i]=new_array[i];
        }
        array[index]=item;

    delete[] new_array;
    }
 index++;
}
template<class T>
void Queue<T>::pop(){
    //index must be greater than zero
    if(index>0){
        //creating new array to store old one
        T *new_array;
        new_array = new T[Max_size];
        //j is the new array index startint neg since we are deleting the head
        int j=-1;
        for(int i=1; i<=index;i++){
           j++;
            new_array[j]=array[i];
        }
        //creating an array
        array= new T[Max_size];
        index--;
        //copying arrays
        for(int i=0; i<=index;i++){
            array[i]=new_array[i];
        }
        delete[] new_array;

    }else{
        //if user tries to go under zero index
        index=0;
         array[index]=NULL;
    }
}
template<class T>
bool Queue<T>::empty(){
    // if array is empty
    if(index!=0){
        return false;
    }
    return true;
}

//void Queue::print(){

//}

template<class T>
T Queue<T>::top(){
    //return the next pop int
    if(index!=0){
    return array[0];
    }
    return NULL;
}

template<class T>
int Queue<T>::get_index(){
    return index;
}

#endif // QUEUE_H
