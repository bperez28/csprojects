#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
T maximal(const T& a, const T& b){
    //return the larger of the two items
    if(a<b){
        return b;
    }else if(b<a){
        return a;
    }
}

template <class T>
void destroy_array(T* &src){
    if (src){
        delete[] src;
    }
    src = NULL;
}

template <class T>
T* copy_array(T* src, int size){
    T* copy = new T[size];
    for (int i=0; i<size; i++){
        copy[i] = src[i];
    }
    return copy;
}


template <class T>
void clear_array(T array[],int &size){
//    for(int i=0; i<=size; i++){
//        array[i]=0;
//    }
    size=0;
}

template <class T>
void _swap(T& a, T& b)  //swap the two items
{

    T hold = b;
    b = a;
    a = hold;

}

template <class T>
int index_of_maximal(T data[ ], int n)                 //return index of the largest item in data
{
    int m;
    T dest[n];
    copy_array(dest,data,m,n);
    assend_array(dest,m);
    return m;
}

template <class T>
void ordered_insert(T data[], int& n, T entry){       //insert entry into the sorted array
    //data with length n
    data[n]=entry;
    n++;

    if(n>1){
        for (int i=1; i <n ; i++)
        {
            _swap(data[i-1],data[i]);
        }

    }
}

template <class T>
int first_ge( T data[ ], int n, const T& entry){   //return the first element in data that is
    //not less than entry
   for(int i=0; i<n;i++){
       if(data[i]>=entry){
           return i;
       }
   }
   return n;

}

template <class T>
void attach_item(T data[ ], int& n, const T& entry){    //append entry to the right of data
    if(n>=0){
        data[n]=entry;
        n++;
    }

}

template <class T>
void _split(T data1[], int &n1, T data2[], int &n2){
    //1. find the middle
    n2=n1/2;
    int i=0;

    for(int j=n1-n2;j<n1;j++)
    {
        data2[i]=data1[j];
        i++;
    }

    n1=n1-n2;

}

template <class T>
void insert_item(T data[ ], int i, int& n, T entry){    //insert entry at index i in data
    if(i>=0){

        for(int j=n;j>i;--j){

            data[j]=data[j-1];

        }
        ++n;
        data[i]=entry;
    }

}

template <class T>
void detach_item(T data[ ], int& n,T& entry){          //remove the last element in data and place
    //it in entry
    entry=data[n-1];

    n--;
}

template <class T>
void delete_item(T data[ ], int i, int& n,T& entry){
    //delete item at index i and place it in entry
    if(i>=0){
        entry=data[i];
//        data[i]=0;
        for(int j=i; j<=n-1;j++){
            _swap(data[j],data[j+1]);
        }
        n--;
    }

}

template <class T>
void merge(T data1[ ], int& n1, T data2[ ], int& n2){   //append data2 to the right of data1

    for(int i=0; i<=n2-1; i++){
        data1[n1]=data2[i];
        n1++;
    }


}

template <class T>
void copy_array(T dest[],  const T src[],
                int& dest_size, int src_size){              //copy src[] into dest[]
    for(int i=0; i<=src_size-1;i++){
        dest[i]=src[i];
        dest_size++;
    }

}
//template <class T>
//    void assending_array(T data[],int n){
//        for(int i=0; i<n;i++){
//            swap(data[i],data[i+1]);
//        }
//    }
template <class T>
void print_array(const T data[], int n){  //print array data
    for(int i=0; i<n;i++){
        cout<<"|";
        cout<<data[i];

    }
    cout<<"|";
    cout<<endl;

}

template <class T>
bool is_gt(const T data[], int n, const T& item){       //item > all data[i]
    for(int i=0; i<=n; i++){
        if(data[i]<item){
            return true;
        }
    }
    return false;
}
template <class T>
bool is_le(const T data[], int n, const T& item){      //item <= all data[i]
    for(int i=0; i<=n; i++){
        if(data[i]>item){
            return true;
        }
    }
    return false;

}

template <class T>
bool array_contain(const T data[], int n, const T& item){      //item <= all data[i]
    for(int i=0; i<=n; i++){
        if(data[i]==item){
            return true;
        }
    }
    return false;

}
template <class T>
int array_find(const T data[], int n, const T& item){      //item <= all data[i]
    for(int i=0; i<=n; i++){
        if(data[i]==item){
            return i;
        }
    }
    return -1;

}
//-------------- Vector Extra operators: ---------------------

template <typename T>
ostream& operator <<(ostream& outs, const vector<T>& list){
    //print vector list
    for(int i=0; i<list.size();i++){
        cout<<list.at(i);
        cout<<" ";
    }
}

template <typename T>
vector<T>& operator +=(vector<T>& list, const T& addme){
    list.push_back(addme);

}

#endif // ARRAY_FUNCTIONS_H
