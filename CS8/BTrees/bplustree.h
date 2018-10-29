#ifndef BPLUSTREE_H
#define BPLUSTREE_H
#include "array_functions.h"
#include "assert.h"
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class BPlusTree
{
public:

    class Iterator{
    public:
        //friend class to excess the BPlusTree
        friend class BPlusTree;
        //constructor
        Iterator(BPlusTree<T>* _it=NULL, int _key_ptr = 0):it(_it), key_ptr(_key_ptr){ }

        //deconstuctor
        T& operator *(){
            //while return an error if condition meet
            assert(key_ptr<it->data_count);
            return it->data[key_ptr];
        }


        //         friend Iterator operator ++(Iterator& _it,
        //                                    int unused){
        //            Iterator hold;
        //            hold=_it;
        //            _it.it++;
        //            return hold;
        //        }

        //when iterating an Iterator makes sure it doesn't
        //go over the data_count
        Iterator operator ++(){

            ++key_ptr;
            if(key_ptr >= it->data_count){
                key_ptr=0;
                it=it->next;

            }

        }
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs){
            return (lhs.it==rhs.it);
        }

        //        friend bool operator ==(const Iterator& lhs, const T& entry){
        //            return array_contain(lhs.it->data,lhs.it->data_count,entry);

        //        }
        //        friend bool operator !=(const Iterator& lhs, const T& entry){
        //            return (!array_contain(lhs.it->data,lhs.it->data_count,entry));

        //        }

        //        Iterator& operator =(const Iterator& R){
        //            if(this->it!=R.it){
        //                this->it=R.it;
        //                this->key_ptr=R.key_ptr;
        //                return *this;
        //            }
        //        }

        friend bool operator !=(const Iterator& lhs, const Iterator& rhs){
            return (lhs.it!=rhs.it);
        }

        void print_Iterator(){
            //            cout<<"Iterator print"<<endl;

            cout<<it->data[key_ptr];
            cout<<endl;
        }
        bool is_null(){return !it;}
        //    private:
        BPlusTree<T>* it;
        int key_ptr;
    };

    //if dups is true it allows to add every new item
    //regradless if it exist in the BPlusTree
    BPlusTree(bool dups = false);

    //big three:
    BPlusTree(const BPlusTree<T>& other);
    BPlusTree(const T other[], int index);

    ~BPlusTree(){
        clear_tree();
    }

    BPlusTree<T>& operator =(const BPlusTree<T>& RHS){

            clear_tree();
            copy_tree(RHS);

        return *this;
    }
    //insert calls loose_insert and inside calls fix_excess if needed
    //after loose insert top is check to fix_excess
    void insert(const T& entry);

    //this is still not implimated tp the program
    T remove(const T& entry);
    //remove entry from the tree

    //goes to the right side of the tree clears that
    //than comes back recursivly to clear the rest
    void clear_tree();
    //clear this object (delete all nodes etc.)

    //copies the tree
    void copy_tree(const BPlusTree<T>& other);
    //copy other into this object
    void copy_tree(const BPlusTree<T>& other,  vector<BPlusTree<T> *> &hold);

    //checks if the tree has the item and returns
    //true if it does an false if it doesnt
    bool contains(const T& entry);
    //true if entry can be found in the array

    T& get(const T& entry);
    //return a reference to entry in the tree

    //returns Iterator once found
    typename BPlusTree<T>::Iterator  find(const T& entry);


    int size() const;
    //count the number of elements in the tree

    bool empty() const;
    //true if the tree is empty

    //this is called in the << operator
    void print_tree(int level = 0, ostream& outs = cout) const;

    friend ostream& operator<<(ostream& outs, const BPlusTree<T>& print_me){
        print_me.print_tree();

    }
    //this is for debuging
    bool is_valid();

    //returns Iterator of get_smallest_node
    typename BPlusTree<T>::Iterator Begin() ;

    //this is just a Iterator of NULL
    typename BPlusTree<T>::Iterator End() ;


    //    private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;
    bool dups_ok;
    //true if duplicate keys may be inserted
    int tree_size;
    int data_count=0;                                 //number of data elements
    T data[MAXIMUM + 1];                            //holds the keys
    int child_count=0;                                //number of children
    BPlusTree<T> *subset[MAXIMUM + 2];                    //subtrees
    BPlusTree<T> *next;
    BPlusTree<T> *smallest_node;

    bool is_leaf() const
    {return child_count==0;}        //true if this is a leaf node

    T* find_ptr(const T& entry);        //return a pointer to this key. NULL if not there.

    //insert element functions
    void loose_insert(const T& entry);  //allows MAXIMUM+1 data elements in the root
    void fix_excess(int i);             //fix excess of data elements in child i

    //remove element functions:
    void loose_remove(const T& entry);  //allows MINIMUM-1 data elements in the root

    BPlusTree<T>* fix_shortage(int i);  //fix shortage of data elements in child i
    T& get_existing(const T& entry);                                  // and return the smallest key in this subtree
    BPlusTree<T> *get_smallest_node();
    void get_smallest(T& entry);        //entry := leftmost leaf
    void get_biggest(T& entry);         //entry := rightmost leaf
    void remove_biggest(T& entry);      //remove the biggest child of this tree->entry
    void transfer_left(int i);          //transfer one element LEFT from child i
    void transfer_right(int i);         //transfer one element RIGHT from child i
    BPlusTree<T>* merge_with_next_subset(int i);    //merge subset i with subset i+1
    void rotate_left(int i);
    void rotate_right(int i);

};

//if dubs is true than items are added even if they already exist
//this also sets every count to zero
//sets subsets to NULL
template <class T>
BPlusTree<T>::BPlusTree(bool dups){
    dups_ok=dups;
    data_count=0;

    for(int i=0; i<MAXIMUM+2; i++){
        subset[i]=NULL;
    }
    child_count=0;
    next=NULL;
}


//big three:
template <class T>
BPlusTree<T>::BPlusTree(const BPlusTree<T>& other){
    this->clear_tree();
    this->copy_tree(other);

}
template <class T>
BPlusTree<T>::BPlusTree(const T other[], int index){
    copy_array(data,other,data_count,index);

}

template <class T>
void BPlusTree<T>::insert(const T& entry){
    //insert entry into the tree
    //inside loose_insert fix_excess is called if needed
    loose_insert(entry);
    //this checks if the top need to be fixed
    if(this->data_count>MAXIMUM){

        BPlusTree<T> *b= new BPlusTree<T>();

        copy_array(b->data,data,b->data_count,data_count);
        copy_array(b->subset, subset,b->child_count,child_count);
        subset[0]=b;
        child_count=1;
        data_count=0;
        b=NULL;

        fix_excess(0);
    }



}

//this is not implemented currently in the program
template <class T>
T BPlusTree<T>::remove(const T& entry){
    //remove entry from the tree
    loose_remove(entry);

    if(this->data_count<MINIMUM){
        BPlusTree<T> *b= new BPlusTree<T>();

        //            copy_array(b->data, subset,b->data_count,child_count);



    }


}

//goes to the whole tree recursivly and clear all
template <class T>
void BPlusTree<T>::clear_tree(){
    //clear this object (delete all nodes etc.)
    if(is_leaf()){


    }else{
        for(int i=this->child_count-1; i>=0; i--){
            subset[i]->clear_tree();
        }
        if(!is_leaf()){
            for(int i=child_count-1;i>=0;i--){
                data_count=0;
                delete subset[i];
            }
            child_count=0;
            data_count=0;
        }
    }

}
//copies the tree
template <class T>
void BPlusTree<T>::copy_tree(const BPlusTree<T>& other){
    //copy other into this object

   vector<BPlusTree<T>*> hold;
   copy_tree(other,hold);
   this->get_smallest_node()->next=NULL;
}
template <class T>
void BPlusTree<T>::copy_tree(const BPlusTree<T>& other, vector<BPlusTree<T>*>& hold){
    //copy other into this object
    copy_array(this->data,other.data,this->data_count,other.data_count);
    this->child_count=other.child_count;
    for(int i=this->child_count-1; i>=0; i--){

        this->subset[i]= new BPlusTree<T>();
        this->subset[i]->copy_tree(*other.subset[i],hold);

        if(this->subset[i]->is_leaf()&& i<=this->child_count-1 && hold.empty()){

            this->subset[i]->next=this->subset[i+1];

            if(i==0){
                hold.push_back(this->subset[i]);
            }
        }else if(i==this->child_count-1 && this->subset[i]->is_leaf()){

            if(!hold.empty()){
                this->subset[i]->next=hold.front();
                hold.pop_back();
            }
        }
    }
}
//checks if the tree contains the entry
//if it does than return true if not than return false
template <class T>
bool BPlusTree<T>::contains(const T& entry){
    //true if entry can be found in the array

    int i = first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i]==entry);
    if(found){
        return true;
    }else{
        if (is_leaf()){
            return false;
            //exit(-1);
        }else{
            return subset[i]->contains(entry);
        }
    }
}
//this returns the ref of where the entry is at
//if the entry is not found in contains than insert it
template <typename T>
T& BPlusTree<T>::get(const T& entry) {
    //If entry is not in the tree, add it to the tree
    //assert(contains(entry));

    const bool debug = false;
    if (!contains(entry)){
        insert(entry);
    }

    return get_existing(entry);
}
//this functions assumes the entry is already in the tree
//since its called from the get function which inserts if
//not found
template <typename T>
T& BPlusTree<T>::get_existing(const T& entry) {
    /*
 * ---------------------------------------------------------------
 * This routing explains plainly how the BPlusTree is organized.
 * i = first_ge
 *       |      found         |    !found         |
 * ------|--------------------|-------------------|
 * leaf  |  you're done       | it's not there    |
 *       |                    |                   |
 * ------|--------------------|-------------------|
 * !leaf | subset[i+1]->get() |  subset[i]->get() |
 *       | (inner node)       |                   |
 * ------|--------------------|-------------------|
 *       |                    |                   |
 *
 * ---------------------------------------------------------------
 *
 */
    //assert that entry is not in the tree.
//    assert(contains(entry));

    const bool debug = false;
    int i = first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i]==entry);
    if (is_leaf()){
        if (found){
            return data[i];
        }else{
            if (debug) {
//                cout<<"get_existing was called with nonexistent entry"<<endl;
            assert(found);
            }
        }
    }else{
        if(found){ //inner node
//            cout<<"recurse is found"<<endl;
            return subset[i+1]->get_existing(entry);
            //or just return true?
        }else{ //not found yet...
//            cout<<"recurse not found"<<endl;
            return subset[i]->get_existing(entry);
        }

    }
}
//this finds the entry and return it with an Iterator
//it does this because i dont want the user to change the tree
template <class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::find(const T& entry){
    //return a pointer to this key. NULL if not there.
    BPlusTree<T>* walker =this;
    int i = first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i]==entry);
    if (found){
        return Iterator(walker,i);

    }else{
        if (is_leaf()){
            //            cout<<"get called with non-existent entry: "<<entry<<endl;
            //            insert(entry);
            //            return find(entry);

            //exit(-1);
        }else{
            return subset[i]->find(entry);
        }
    }
}
//keeps track of the tree every time it inserts into the tree
// and subtracts when removing
template <class T>
int BPlusTree<T>::size() const{
    //count the number of elements in the tree
    return tree_size;
}
//this just check if the tree is empty
template <class T>
bool BPlusTree<T>::empty() const{
    //true if the tree is empty
    return (data_count==0 && child_count==0);


}
//prints the tree
template <class T>
void BPlusTree<T>::print_tree(int level, ostream& outs) const{

    if(this->child_count==0){
        cout<<setw(((level)*5)+2);
        cout<<"^";
        cout<<endl;
        cout<<setw(((level)*5)+2);
        cout<<"|";
        cout<<endl;
        cout<<setw((level)*5);
        cout<<"-";
        print_array(this->data,this->data_count);

        return;
    }else{
        int j=this->child_count-1;
        for(int i=this->data_count;i>=0;i--){
            this->subset[j]->print_tree(level+1,cout);
            if(j==1){
                cout<<setw((level)*5);
                cout<<"-";
                print_array(this->data,this->data_count);
                cout<<endl;
            }
            j--;

        }
        //            this->subset[0]->print_tree(level+1,cout);
        return;

    }
}

// this will be use for debuging
template <typename T>
bool BPlusTree<T>::is_valid(){

    //should check that every data[i] < data[i+1]
    if (is_leaf())
        return true;


    //data[data_count-1] must be less than equal to
    //  every subset[child_count-1]->data[ ]

    //every data[i] is greater than every subset[i]->data[ ]

    //B+Tree: Every data[i] is equal to subset[i+1]->smallest

    //Recursively validate every subset[i]

    return true;
}
//this inserts the item
//insert element functions
template <class T>
void BPlusTree<T>::loose_insert(const T& entry){
    //allows MAXIMUM+1 data elements in the root

    int i = first_ge(data, data_count, entry);

    bool found = (i<data_count && data[i] == entry);

    if(found){


    }else{

        if(this->is_leaf()){

             insert_item(this->data,i,this->data_count,entry);

        }else{
              subset[i]->loose_insert(entry);

        }

    }

    if(!this->is_leaf() && this->subset[i]->data_count>MAXIMUM){

        fix_excess(i);
    }



}
//this is called in loose_insert and insert
//its when data_count is over the max
template <class T>
void BPlusTree<T>::fix_excess(int i){
    //fix excess of data elements in child i

    insert_item(this->subset,i+1,this->child_count, new BPlusTree<T>);
    _split(this->subset[i]->data,this->subset[i]->data_count,
           this->subset[i+1]->data,this->subset[i+1]->data_count);
    _split(this->subset[i]->subset,this->subset[i]->child_count,
           this->subset[i+1]->subset,this->subset[i+1]->child_count);
    subset[i+1]->next=subset[i]->next;


    T max;
    detach_item(this->subset[i]->data,this->subset[i]->data_count,max);

    if(this->subset[i]->is_leaf()){
        ordered_insert(this->subset[i+1]->data,this->subset[i+1]->data_count,max);
        //        insert_item(this->subset[i+1]->data,0,this->subset[i+1]->data_count,max);
        subset[i]->next=subset[i+1];
//        smallest_node=subset[0];
    }

    //        int f_g=first_ge(this->data,this->data_count,max);

    insert_item(this->data,i,this->data_count,max);

}


//remove element functions:
template <class T>
void BPlusTree<T>::loose_remove(const T& entry){
    //allows MINIMUM-1 data elements in the root
    int i = first_ge(data, data_count, entry);

    T item;
    bool found = (i<data_count && data[i] == entry);
    if(found){

        if(this->is_leaf()){
            delete_item(data,i,data_count,item);




        }else{
            delete_item(data,i,data_count,item);
            delete_item(subset[i+1]->data,0,subset[i+1]->data_count,item);
            subset[i]->loose_remove(entry);

        }

    }else{
        if(this->is_leaf()){
            // do nothing

        }else{
            subset[i]->loose_remove(entry);
        }


    }

    if(!this->is_leaf() && this->subset[i]->data_count<MINIMUM){
        fix_shortage(i);
    }



}
template <class T>
BPlusTree<T>*  BPlusTree<T>::fix_shortage(int i){
    //fix shortage of data elements in child i
    /*
       * fix shortage in subtree i:
       * if child i+1 has more than MINIMUM, rotate left
       * elif child i-1 has more than MINIMUM, rotate right
       * elif there is a right child, merge child i with next child
       * else merge child i with left child
       */

    if(i!=0){
        if(this->subset[i+1]->data_count>MINIMUM){
            cout<<"rotating left"<<endl;
            rotate_left(i);
        }else if(this->subset[i-1]->data_count>MINIMUM){
            cout<<"rotating right"<<endl;
            rotate_right(i);
        }else if(this->subset[i+1]->data_count>0){
            cout<<"merging with next subset(i)"<<endl;
            merge_with_next_subset(i);
        }else{
            cout<<"merging with next subset(i-1)"<<endl;
            merge_with_next_subset(i-1);
        }
    }else{
        if(this->subset[i+1]->data_count>MINIMUM){
            cout<<"rotating left"<<endl;
            rotate_left(i);
        }else if(this->subset[i+1]->data_count>0){
            cout<<"merging with next subset(i)"<<endl;
            merge_with_next_subset(i);
        }

    }
}
template <class T>
void BPlusTree<T>::transfer_left(int i){
    //transfer one element LEFT from child i
}
template <class T>
void BPlusTree<T>::transfer_right(int i){
    //transfer one element RIGHT from child i
}

template <class T>
void BPlusTree<T>::remove_biggest( T& entry){
    //remove the biggest child of this tree->entry
    // Keep looking in the last subtree (recursive)
    //  until you get to a leaf.
    // Then, detach the last (biggest) data item
    //
    // after the recursive call, fix shortage.
    int i = first_ge(data, data_count, entry);

    if(this->is_leaf()){

        detach_item(this->data,this->data_count,entry);
    }else{
        subset[i]->remove_biggest(entry);
    }


}
template <class T>
void BPlusTree<T>::rotate_left(int i){
    //transfer one element LEFT from child i
    /*
        * (0 < i < child_count) and (subset[i]->data_count > MINIMUM)
        * subset[i-1] has only MINIMUM - 1 entries.
        *
        * item transfers from child[i] to child [i-1]
        *
        * FIRST item of subset[i]->data moves up to data to replace data[i],
        * data[i] moves down to the RIGHT of subset[i-1]->data
        *
        *  i = 1:
        *              [50 100]
        *  [  ]        [65 75]       ....
        *            [a]  [b]  [c]
        *
        *  65 move up to replace 50 (data[i])
        *  65's child (its child 0) moves over to be the child of 50
        *  50 moves down to the right of subset[i]->data
        *
        *              [65 100]
        *  [50]         [ 75 ]       ....
        *     [a]      [b]  [c]
        *
        *
        *
        *
        * last item of subset[i-1]->data moves up to data,
        * data[i] moves down to the RIGHT of subset[i]->data
        */
    // If necessary, shift first subset of subset[i] to end of subset[i-1]

    if((0 < i < child_count) && (subset[i]->data_count > MINIMUM)){

    }



}
template <class T>
void BPlusTree<T>::rotate_right(int i){
    //transfer one element RIGHT from child i
    /* (i < child_count - 1) and (subset[i]->data_count > MINIMUM)
         * subset[i+ 1] has only MINIMUM - 1 entries.
         *
         * item transfers from child[i] to child [i+1]
         *
         * LAST item of subset[i]->data moves up to data to replace data[i],
         * data[i] moves down to the LEFT of subset[i+1]->data
         *
         * i = 1
         *                     [50 100]
         *      [20 30]        [65 75]          [ ]
         *  [..] [..] [..]   [a] [b] [c]        [..]
         *
         *  75 moves up to replace 100 (data[i])
         *  75's child (its last child) moves over to be the (child 0) child of 100
         *  100 moves down to subset[i]->data
         *
         *                     [50 75]
         *      [20 30]          [65]          [100]
         *  [..] [..] [..]     [a] [b]        [c] [..]
         *
         *
         *
         *
         * last item of subset[i-1]->data moves up to data,
         * data[i] moves down to the RIGHT of subset[i]->data
         */
    // If necessary, shift last subset of subset[i] to front of subset[i+1]
    if((i < child_count - 1) && (subset[i]->data_count > MINIMUM)){

    }

}
template <class T>
BPlusTree<T>* BPlusTree<T>::merge_with_next_subset(int i){
    //merge subset i with subset i+1
    /*
        *  Merge subset[i] with subset [i+1] with data[i] in the middle
        *
        *   1. remove data[i] from this object
        *   2. append it to child[i]->data
        *   3. Move all data items from subset[i+1]->data to subset[i]->data
        *   4. Move all subset pointers from subset[i+1]->subset to subset[i]->subset
        *   5. delete subset[i+1] (store in a temp ptr)
        *   6. delete temp ptr
        */
    T object;
    delete_item(this->data,i,this->data_count,object);
    attach_item(this->subset[i]->data,this->subset[i]->data_count,object);
    if(this->child_count>0){
        merge(subset[i]->data,subset[i]->data_count,
              subset[i+1]->data,subset[i+1]->data_count);
        merge(subset[i]->subset,subset[i]->child_count,
              subset[i+1]->subset,subset[i+1]->child_count);
    }

    // dont know how to delete subset[i+1]
    BPlusTree<T>* entry;
    delete_item(subset,i+1,child_count,entry);
}
template <class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::Begin(){
    //C++ requires you to use the keyword typename when referring to the Iterator outside
    //      the class declaration
    //the top next points to the smallest node at

    return Iterator(get_smallest_node());
}

template <class T>
typename BPlusTree<T>::Iterator BPlusTree<T>::End(){

    return Iterator(NULL);

}

//the smallest leaf node when fix_excess just return the
//pointer
template <class T>
BPlusTree<T>* BPlusTree<T>::get_smallest_node(){
    if(is_leaf()){
        return this;
    }else{
        return subset[0]->get_smallest_node();
    }
}

template <class T>
void BPlusTree<T>::get_smallest(T& entry){
    //entry := leftmost leaf
    //replace entry with the left_most leaf of this tree
    // Keep looking in the first subtree (recursive)
    //  until you get to a leaf.
    // Then, replace entry with data[0] of the leaf node
    const bool debug = false;
}
template <class T>
void BPlusTree<T>::get_biggest(T& entry){
    //entry := rightmost leaf

}

#endif // BPLUSTREE_H
