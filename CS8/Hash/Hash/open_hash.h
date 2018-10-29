#ifndef OPEN_HASH_H
#define OPEN_HASH_H
#include <cstdlib>
#include <iostream>
using namespace std;

template <class R>
class open_hash
{
public:
    static const int CAPACITY = 16;
    open_hash();
    void insert(const R& entry);
    //insert record if no match key
    //   if same key found replace it
    void remove(int key);
    //if record is in has remove it,
    //   not found leave alone
    bool is_present(int key) const;
    //if a matching key found return true
    // otherwise false
    void find(int key, bool& found, R& result) const;
    //if key is found value for found= true
    //and result changes to the record
    int size( ) const{ return used;}
    // return total value of records

    friend ostream& operator <<(ostream& outs, const open_hash<R>& print_me){
        for(int i=0; i<=CAPACITY-1;i++){
            cout<<"["<<i<<"]"<<" ";
            cout<<print_me.data[i];
            if(print_me.collision[i]>0){
                for(int j=0; j<=print_me.collision[i]-1;j++){
                    cout<<" *";
                }
            }
            cout<<endl;
        }

    }


    private:
    // MEMBER CONSTANTS -- These are used in the key field of special records. static const int NEVER_USED = -1;
    static const int PREVIOUSLY_USED = -2;
    static const int NEVER_USED = -1;
    // MEMBER VARIABLES
    R data[CAPACITY];
    int collision[CAPACITY];
    int used;
    // HELPER FUNCTIONS
    int hash(int key) const;
    //hashes a key to an array index
    int next_index(int index) const;
    //next_index usually returns i + 1
    //except if i is the end of the array
    void find_index(int key, bool& found, int& index) const;
    //goes through the array if key is found set found=true
    // than set the index to where its placed in the array
    bool never_used(int index) const;
    //if the index has never been used
    bool is_vacant(int index) const;
    //if the space is not currently used


};

template <class R>
open_hash<R>::open_hash()
{
    for(int i=0; i<=CAPACITY-1; i++){
        data[i]=R(NEVER_USED,NEVER_USED);
        collision[i]=0;
    }
    used=0;


}

template <class R>
void open_hash<R>::insert(const R& entry){
    //insert record if no match key
    //   if same key found replace it
    if(used!=CAPACITY-1){
    int key;
    key>>entry;
    int index=hash(key);
    bool found;
    bool inserted=false;
    while(!inserted){
        if(is_vacant(index)){
            if(never_used(index)){
                data[index]=entry;
                used++;
                inserted=true;

            }else{

                int i;
                find_index(key,found,i);
                if(found){
                    data[i]=entry;
                    inserted=true;

                }else{
                    data[index]=entry;
                    used++;
                    inserted=true;
                }
            }

        }else{
            collision[index]=1;
            index=next_index(index);

        }

    }

}else{
//        cout<<"hash is full"<<endl;
    }

}

template <class R>
void open_hash<R>::remove(int key){
    //if record is in has remove it,
    //   not found leave alone
    if(used!=0){
    int index;
    bool found=false;
    find_index(key,found,index);
    if(found){
        data[index]>>-2;//-2 is prevously used
        used--;
        collision[index]=0;
    }else{
        cout<<"was not found to remove"<<endl;
    }
    }else{
        cout<<"hash is empty"<<endl;
    }
}

template <class R>
bool open_hash<R>::is_present(int key) const{
    //if a matching key found return true
    // otherwise false
    int i;
    bool found;
    find_index(key,found,i);
    return found;
}

template <class R>
void open_hash<R>::find(int key, bool& found, R& result) const{
    //if key is found value for found= true
    //and result changes to the record
    int index;
    find_index(key,found,index);
    if(found){
        result=data[index];
    }else{
//        cout<<"was't found"<<endl;
    }
}
template <class R>
int  open_hash<R>::hash(int key) const{
    //hashes a key to an array index
    return (key%CAPACITY);
}
template <class R>
int open_hash<R>::next_index(int index) const{
    //next_index usually returns i + 1
    //except if i is the end of the array
    return ((index+1)%CAPACITY);
}
template <class R>
void  open_hash<R>::find_index(int key, bool& found, int &index) const{
    //goes through the array if key is found set found=true
    // than set the index to where its placed in the array
    int i=hash(key);
    while(index>=0){
        if(never_used(i)){
            found=false;
            return;
        }else{
            if(data[i]==R(key)){
                found=true;
                index=i;
                return;
            }else{

                i=next_index(i);
            }
        }
    }
}
template <class R>
bool  open_hash<R>::never_used(int index) const{
    //if the index has never been used
    if(data[index]==R(NEVER_USED)){
        return true;
    }else{
        return false;
    }
}
template <class R>
bool  open_hash<R>::is_vacant(int index) const{
    //if the space is not currently used
    if(data[index]==R(NEVER_USED) || data[index]==R(PREVIOUSLY_USED) ){
        return true;
    }else{
        return false;
    }
}


#endif // OPEN_HASH_H
