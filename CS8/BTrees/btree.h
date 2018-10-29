#ifndef BTREE_H
#define BTREE_H
#include"array_functions.h"
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class BTree
{
public:
    BTree(bool dups = false){

    }


    //big three:
    BTree(const BTree<T>& other){
        clear_tree();

    }
    BTree(const T other[], int index){

        copy_array(data,other,data_count,index);

    }

    ~BTree(){

        //                  delete[]data;
        //            subset=NULL;
    }

    BTree<T>& operator =(const BTree<T>& RHS){
        if(this->data_count!=RHS.data_count){
            for(int i=0; i<=RHS.data_count-1;i++){
                if(this->data[i]!=RHS.data[i]){
                    this->clear_tree();
                    this->copy_tree(RHS);
                    return *this;
                }
            }
        }

    }

    void insert(const T& entry){
        //insert entry into the tree
        cout<<"inserting"<<entry<<endl;
        loose_insert(entry);
        if(this->data_count>MAXIMUM){
            cout<<"insert top fix_excess"<<endl;
            BTree<T> *b= new BTree<T>();

            copy_array(b->data,data,b->data_count,data_count);
            copy_array(b->subset, subset,b->child_count,child_count);

            data_count=0;
            child_count=1;
            subset[0]=b;
            //          b=NULL;

            fix_excess(0);

        }


    }
    T remove(const T& entry){
        //remove entry from the tree
        loose_remove(entry);

        if(this->data_count<MINIMUM && !this->is_leaf()){
            cout<<"insert top fix_shortage"<<endl;
            BTree<T> *b= new BTree<T>();
            copy_array(b->data,subset[0]->data,b->data_count,subset[0]->data_count);
            copy_array(b->subset, subset,b->child_count,child_count);
            copy_array(this->data,b->data,this->data_count,b->data_count);
//            b->data_count=0;
            copy_array(this->subset,b->subset,this->child_count,b->child_count);
            print_array(data,data_count);

        }


    }


    void clear_tree(){
        //clear this object (delete all nodes etc.)
        this->data_count=0;
        this->child_count=0;
    }
    void copy_tree(const BTree<T>& other){
        //copy other into this object

        if(other.data_count==0){
            return;
        }else{
            copy_array(this->data,other.data,this->data_count,other.data_count);
            this->child_count=other.child_count;
            for(int i=0; i<=other.child_count;i++){
                this->subset[i]->copy_tree(other.subset[i]);
            }

        }
    }

    bool contains(const T& entry){
        //true if entry can be found in the array

    }
    T& get(const T& entry){
        //return a reference to entry in the tree

        //If entry is not in the tree, CRASH
        //assert(contains(entry));

        int i = first_ge(data, data_count, entry);
        bool found = (i<data_count && data[i]==entry);
        if (found){
            return data[i];
            if (is_leaf()){
                cout<<"get called with non-existent entry: "<<entry<<endl;
                insert(entry);
                return get(entry);

                //exit(-1);
            }
        }else{//yet...
            return subset[i]->get(entry);
        }

    }
    T* find(const T& entry){
        //return a pointer to this key. NULL if not there.

        int i = first_ge(data, data_count, entry);
        bool found = (i<data_count && data[i]==entry);
        if (found)
            return data[i];
        if (is_leaf()){
            cout<<"get called with non-existent entry: "<<entry<<endl;
            insert(entry);
            return find(entry);

            //exit(-1);
        }
        if (!found)  //yet...
            return subset[i]->find(entry);
    }

    int size() const{
        //count the number of elements in the tree

    }
    bool empty() const{
        //true if the tree is empty
        if(this->is_leaf()){
            if(data_count==0){
                return true;
            }
        }
        return false;


    }

    void print_tree(int level = 0, ostream& outs = cout) const{

        if(this->child_count==0){
            cout<<setw((level)*5);
            cout<<"-";
            print_array(this->data,this->data_count);
            cout<<"D:"<<this->data_count;
            cout<<"/C:"<<this->child_count;

            cout<<endl;
            return;
        }else{
            int j=this->child_count-1;
            for(int i=this->data_count;i>=0;i--){
                this->subset[j]->print_tree(level+1,cout);
                if(j==1){
                    cout<<setw((level)*5);
                    cout<<"-";
                    print_array(this->data,this->data_count);
                    cout<<"D:"<<this->data_count;
                    cout<<"/C:"<<this->child_count;
                    cout<<endl;
                }
                j--;

            }
            //            this->subset[0]->print_tree(level+1,cout);
            return;

        }
    }

    friend ostream& operator<<(ostream& outs, const BTree<T>& print_me){
        print_me.print_tree();
        return outs;
    }

    //    private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;
    bool dups_ok;
    //true if duplicate keys may be inserted
    int _height;
    int data_count=0;                                 //number of data elements
    T data[MAXIMUM + 1];                            //holds the keys
    int child_count=0;                                //number of children
    BTree<T> *subset[MAXIMUM + 2];                     //subtrees

    bool is_leaf() const {
        if(this->child_count==0){
            return true;
        }else{
            return false;
        }
    }   //true if this is a leaf node

    //insert element functions
    void loose_insert(const T& entry){
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
    void fix_excess(int i){
        //fix excess of data elements in child i
        cout<<"fixing_excess:"<<i<<endl;
        insert_item(this->subset,i+1,this->child_count, new BTree);

        _split(this->subset[i]->data,this->subset[i]->data_count,
               this->subset[i+1]->data,this->subset[i+1]->data_count);
        _split(this->subset[i]->subset,this->subset[i]->child_count,
               this->subset[i+1]->subset,this->subset[i+1]->child_count);
        T max;
        detach_item(this->subset[i]->data,this->subset[i]->data_count,max);
        //        int f_g=first_ge(this->data,this->data_count,max);
        insert_item(this->data,i,this->data_count,max);

    }


    //remove element functions:
    void loose_remove(const T& entry){
        cout<<"loose remove"<<endl;
        //allows MINIMUM-1 data elements in the root
        int i = first_ge(data, data_count, entry);

        T item;
        bool found = (i<data_count && data[i] == entry);
        if(found){
            if(this->is_leaf()){
                cout<<"found && is_leaf"<<endl;
                delete_item(data,i,data_count,item);


            }else{
                cout<<"found && !is_leaf"<<endl;
                subset[i]->remove_biggest(item);
                //entry value is changed to biggest in remove_biggest
                this->data[i]=item;
            }

        }else{
            if(this->is_leaf()){
                // do nothing

            }else{
                subset[i]->loose_remove(entry);
            }


        }

        if(!this->is_leaf() && this->subset[i]->data_count<MINIMUM){
            cout<<"fixing shortage:"<<i<<endl;
            fix_shortage(i);
        }



    }
    void fix_shortage(int i){
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




    void remove_biggest( T& entry){
        //remove the biggest child of this tree->entry
        // Keep looking in the last subtree (recursive)
        //  until you get to a leaf.
        // Then, detach the last (biggest) data item
        //
        // after the recursive call, fix shortage.

        if(this->is_leaf()){

            detach_item(this->data,this->data_count,entry);
        }else{
            subset[child_count]->remove_biggest(entry);
        }
        if(!this->is_leaf() && this->subset[child_count]->data_count<MINIMUM){
            cout<<"fixing shortage:"<<child_count<<endl;
            fix_shortage(child_count);
        }



    }
    void rotate_left(int i){
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
            T replacement;
            merge(this->subset[i-1],this->subset[i-1]->child_count,this->subset[i],
                    this->subset[i]->child_count);
            delete_item(this->subset[i]->data,0,
                        this->subset[i]->data_count,replacement);
            T shifting;
            delete_item(this->data,i,this->data_count,shifting);
            insert_item(this->subset[i-1]->data,this->subset[i-1]->data_count,
                    this->subset[i-1]->data_count,shifting);
            insert_item(this->data,i,this->data_count,replacement);

        }



    }
    void rotate_right(int i){
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

//                T replacement;
//                merge(this->subset[i-1],this->subset[i],
//                        this->subset[i-1]->child_count,this->subset[i]->child_count);
//                delete_item(this->subset[i]->data,0,
//                            this->subset[i]->data_count,replacement);
//                T shifting;
//                delete_item(this->data,i,this->data_count,shifting);
//                insert_item(this->subset[i-1]->data,this->subset[i-1]->data_count,
//                        this->subset[i-1]->data_count,shifting);
//                insert_item(this->data,i,this->data_count,replacement);


        }

    }
    void merge_with_next_subset(int i){
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
        BTree<T>* entry;
        delete_item(subset,i+1,child_count,entry);
    }



};

#endif // BTREE_H
