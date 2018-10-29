#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;

template<class T>
class Heap
{
public:
    void insert(const T& insert_me){

        //index must be smaller than array size
        if(index<max_size){
        array[index]=insert_me;
        }
        else{
        //if not we increase the size by making a new array
            max_size=max_size+max_size/2;
            //new array to store old one
            T *new_array;
            new_array= new T[max_size];
            //copying the old array
            for(int i=0; i<=index;i++){
                new_array[i]=array[i];
            }
            //creating a new array
            array= new T[max_size];
            for(int i=0; i<=index;i++){
               array[i]=new_array[i];
            }
            array[index]=insert_me;

        delete[] new_array;
        }
     index++;
     bool hold =true;
     while(hold){

         hold=swap_with_parent(index);

     }

    }
       T Pop(){
           if(!is_empty()){
           int i=0;
            T removing_item=array[i];
            array[i]=array[i+1];
            index=index-1;
            bool hold =true;
            while(hold){

                hold=swap_with_parent(index);

            }
           return removing_item;
       }

           }

       bool is_empty() const{
           if(array[0]==NULL){
               return true;
           }else{
               return false;
           }
       }
       int size() const{
           return max_size;
       }
       int capacity() const{

       }
//       friend ostream& operator << (ostream& outs, const Heap<T>& print_me){
//           for(int i=0; i<print_me.max_size;i++){
//            cout<<print_me.array[i]<<" ";
//           }
//       }

//       void print_tree(ostream& outs = cout) const{

//       }
//       void print_tree(unsigned int root, int level = 0, ostream& outs = cout) const{

//       }

 ~Heap(){
        delete[]array;
       }

//       friend ostream& operator =(const Heap<T>& left, const Heap<T>& right){
//           left.clear();
//           left.array=right.array;
//           left.index=right.index;
//           left.max_size=right.max_size;

//       }

       bool is_leaf(int i) const{
           if(array[left_child_index(i)]==NULL && array[right_child_index(i)]==NULL){
               return true;
           }else{
               return false;
           }
       }
       unsigned int parent_index(int i) const{
           return(i-1)/2;

       }
       int left_child_index(int i)const{
           return(2i+1);
       }
       int right_child_index(int i) const{
           return (2i+2);

       }
       int big_child_index(int i) const{
           int left_child=left_child_index(i);
           int right_child=right_child_index(i);
           if(array[left_child]<array[right_child]){
               return right_child;
           }else{
               return left_child;
           }

       }
       bool swap_with_parent(int i){
           T parent_value= array[parent_index(i)];
           T child_value= array[i];
           if(parent_value<child_value){
             array[parent_index(i)]=child_value;
             array[i]=parent_value;
             return true;
           }else{
               return false;
           }
       }

    Heap(){
        array= new T[max_size];
    }

private:
    T * array;
    int max_size=100;
    int index=0;

};

#endif // HEAP_H
