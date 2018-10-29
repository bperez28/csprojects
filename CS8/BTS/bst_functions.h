#ifndef BST_FUNCTIONS_H
#define BST_FUNCTIONS_H
#include <iostream>
#include"tree_node.h"
#include <iomanip>
using namespace std;

template <typename T>
class BST_Functions
{
public:

     BST_Functions(){

     }


    void tree_insert(tree_node<T>* & root, const T& insert_me){
    //insert item into tree
        if(root==NULL){
       //if the root is null add item there
           root = new tree_node<T>(insert_me);

        }else{

            if(root->_item== insert_me){
                //if the root item is the same as the item
                return;
            }else if(root->_item< insert_me){
                //if the root item is less than item
                //recurse the the right root
                tree_insert(root->_right,insert_me);


            }else if(root->_item > insert_me){
                    //if the root item is greater than item
                //recurse to the left root
                 tree_insert(root->_left,insert_me);
            }
        }
        //update the height
        root->update_height();
         return;


    }
    void avl_tree_insert(tree_node<T>* & root, const T& insert_me){
    //insert item into tree
        if(root==NULL){
       //if the root is null add item there
           root = new tree_node<T>(insert_me);

        }else{

            if(root->_item== insert_me){
                //if the root item is the same as the item
                return;
            }else if(root->_item< insert_me){
                //if the root item is less than item
                //recurse the the right root
                avl_tree_insert(root->_right,insert_me);
//                root->update_height();
//                rotate(root);
//                return;

            }else if(root->_item > insert_me){
                    //if the root item is greater than item
                //recurse to the left root
                 avl_tree_insert(root->_left,insert_me);
//                  root->update_height();
//                  rotate(root);
//                  return;

            }
        }
        //update the height
        root->update_height();
        rotate(root);
         return;


    }
    bool tree_search(tree_node<T>* root, const T& target){
         bool hold;
        if(root==NULL){
            hold= false;
        }else{
            if(root->_item== target){
                //target found
                hold= true;
            }else if(root->_item < target){
                //if the root item is less than item
                //recurse the the right root
                hold =tree_search(root->_right,target);

            }else if(root->_item > target){
                //if the root item is greater than item
                //recurse the the left root
                 hold=tree_search(root->_left,target);
            }
        }

        return hold;
 }

// this conflicted with my prevous function
//    tree_node<T>* tree_search(tree_node<T>* root, const T& target){
//        if(root==NULL){
//            return;
//        }else{
//            if(root->_item== target){
//                return root->_item;
//            }else if(root->_item< target){
//                tree_insert(root->_right,target);

//            }else if(root->_item > target){
//                 tree_insert(root->_left,target);
//            }

//    }
// }

    bool tree_search(tree_node<T>* root, const T& target,
                     tree_node<T>* &found_ptr){
        if(root==NULL){
            return false;
        }else{
            if(root->_item== target){
                //found
                found_ptr=root;
                return true;
            }else if(root->_item< target){
                //if the root item is less than item
                //recurse the the right root
                tree_insert(root->_right,target);

            }else if(root->_item > target){
                //if the root item is greater than item
                //recurse the the left root
                 tree_insert(root->_left,target);
            }

    }
    }


    void tree_print(tree_node<T>* root, int level=0,ostream& outs=cout){

     if(root==NULL){
     return;
     }else{
         tree_print(root->_right,level+1,cout);
         cout<<setw((level)*4);
         cout<<"-"<<root->_item;
         cout<<endl;
         tree_print(root->_left,level+1,cout);
     }

    }

         //prints detailes info about each node
    void tree_print_debug(tree_node<T>* root, int level=0,
                                              ostream& outs=cout){
        if(root==NULL){
            cout<<"clear"<<endl;
        return;
        }else{
            tree_print_debug(root->_right,level+1,cout);

            cout<<setw((level)*4);
            cout<<"-"<<root->_item;
            cout<<"/"<<root->_height;
            cout<<endl;
             tree_print(root->_left,level+1,cout);


        }


    }

      //clear the tree
    tree_node<T>* tree_clear(tree_node<T>* &root){

        if(root==NULL){

          return NULL;
      }else{

          tree_clear(root->_right);

          tree_clear(root->_left);
          //this next process is to prevent leaving data
    //copy root to temp
          tree_node<T>* temp= root;
          //make root null
          root=NULL;

          delete temp;

            return root;
      }


    }

        //erase target from the tree
    bool tree_erase(tree_node<T>*& root, const T& target){
        bool hold;
        if(root==NULL){
            hold= false;
        }else{

            if(root->_item==target){
                hold= true;    

                if(root->_left!=NULL){

               //if the left side is not null
                            //than get the max on that side
                    T max;

                    tree_remove_max(root->_left,max);

                    //make the root eqaul max
                    root->_item=max;
                 }else{
                            //if the left side is null
                            //the root equal make the right side equal
                            tree_node<T>* TEMP;
                            TEMP= root->_right;
                            delete root;
                            root=TEMP;
                   }



            }else if(root->_item<target){
                //if the root item is less than item
                //recurse the the right root
                hold=tree_erase(root->_right,target);
            }else if(root->_item>target){
                //if the root item is greater than item
                //recurse the the left root
                hold=tree_erase(root->_left,target);

            }

            }


        if(root!=NULL){
            root->update_height();
        }

        return hold;


    }
    bool avl_tree_erase(tree_node<T>*& root, const T& target){
        bool hold;
        if(root==NULL){
            hold= false;
        }else{

            if(root->_item==target){
                hold= true;

                if(root->_left!=NULL){

               //if the left side is not null
                            //than get the max on that side
                    T max;

                    tree_remove_max(root->_left,max);

                    //make the root eqaul max
                    root->_item=max;
                 }else{
                            //if the left side is null
                            //the root equal make the right side equal
                            tree_node<T>* TEMP;
                            TEMP= root->_right;
                            delete root;
                            root=TEMP;
                   }



            }else if(root->_item<target){
                //if the root item is less than item
                //recurse the the right root
                hold=avl_tree_erase(root->_right,target);
            }else if(root->_item>target){
                //if the root item is greater than item
                //recurse the the left root
                hold=avl_tree_erase(root->_left,target);

            }

            }


        if(root!=NULL){
            root->update_height();
        }

        return hold;


    }

        //erase rightmost node from the tree
                                // store the item in max_value
    void tree_remove_max(tree_node<T>* &root, T& max_value){
//finds max value and copies the left root of it
        if(root==NULL )
        {
            return;
        }else{
            if(root->_right==NULL){
            max_value=root->_item;

            tree_node<T>* copy_left=root->_left;

            delete root;
           root=copy_left;


            }else{
            tree_remove_max(root->_right,max_value);

            }
        }


        return;

    }

      //return copy of tree pointed to by root
    tree_node<T>* tree_copy(tree_node<T>* root){
        //copies the root and returns it
         tree_node<T>* copied=NULL;
        if(root==NULL){
            return NULL;
        }
            copied = new tree_node<T>(root->_item);
            copied->_height=root->_height;
            copied->_right=tree_copy(root->_right);
            copied->_left=tree_copy(root->_left);
            return copied;


    }

    //tree_add is was not used in the program
          //Add tree src to dest
    void tree_add(tree_node<T>* & dest, const tree_node<T>* src){
        if(src==NULL){
            return;
        }else{

                tree_insert(dest,src->_item);
                tree_add(dest,src->_right);
                tree_add(dest,src->_left);
        }

    }

         // sorted array -> tree
    tree_node<T>* tree_from_sorted_list(const T* a, int start, int end){

        tree_node<T>* copy=NULL;
        //divides the work to two
       int mid=(start+end)/2;
       //makes the value of a[mid] insert in tree
     copy= new tree_node<T>(a[mid]);

          if(start>end){

              return NULL;
          }

            copy->_right=tree_from_sorted_list(a,mid+1,end);
            copy->_left=tree_from_sorted_list(a,start,mid-1);

            return copy;

    }

    // ---------------- ROTATIONS --------------------------
    int sub_child(tree_node<T>* root){
        int l, r;
        if(root->_left==NULL){
            l=-1;
        }else{
            l=root->_left->_height;
        }
        if(root->_right==NULL){
            r=-1;
        }else{
            r=root->_right->_height;
        }
        return l-r;
    }


    tree_node<T>* rotate_right(tree_node<T>* &root){
        if(root==NULL){
            return NULL;
        }else{

            tree_node<T>* copy1= root;
            root=root->_left;
            root->_right=copy1;
            root->_right->_left=NULL;


    }
    }

    tree_node<T>* rotate_left(tree_node<T>* &root){
        if(root==NULL){
            return NULL;
        }else{

            tree_node<T>* copy1= root;
            root=root->_right;
            root->_left=copy1;
            root->_left->_right=NULL;

        }

    }

    tree_node<T>* rotate(tree_node<T>* & root){
        if(root==NULL){
            return NULL;
        }else{

            int child_sub=sub_child(root);

                        if(child_sub>1){
                            if(root->_left->_left==NULL){                            
                                rotate_left(root->_left);
                                rotate_right(root);

                        }else{
                                rotate_right(root);
                            }

                    }else if(child_sub<-1 ){
                            if(root->_right->_right==NULL){
                                        rotate_right(root->_right);
                                      rotate_left(root);

                        }else{
                                rotate_left(root);
                            }
                }


                        root->update_height();

            }


    }
    //-------------------------------------------------------



};

#endif // BST_FUNCTIONS_H
