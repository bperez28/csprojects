#ifndef BST_H
#define BST_H
#include <iostream>
#include "bst_functions.h"
#include"tree_node.h"
using namespace std;

template <typename T>
class BST
{
public:
    BST(){

    }

    BST(const T* sorted_list, int size){
        size--;
        root  = functions.tree_clear(root);
        root = functions.tree_from_sorted_list(sorted_list,0,size);


    }

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    BST(const BST<T>& copy_me){
//         functions.tree_print(copy_me.root);
           root  = functions.tree_clear(root);
           root = functions.tree_copy(copy_me.root);


    }

    BST<T>& operator =(const BST<T>& rhs){
        if(root!=rhs.root){
          functions.tree_clear(root);
          root = functions.tree_copy(rhs.root);
          return *this;
        }
    }


    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void insert(const T& insert_me){
        functions.tree_insert(root,insert_me);
    }

    bool erase(const T& target){
        return functions.tree_erase(root,target);
    }

    bool rootisnull(){
        if(root==NULL){
            return true;
        }else{
            return false;
        }
    }

    void clear(){
        functions.tree_clear(root);
    }

    bool search(const T& target){
            return functions.tree_search(root,target);
    }

    friend ostream& operator <<(ostream& outs, BST<T>& tree){
        tree.functions.tree_print(tree.root,tree.root->_height,outs);
    }

    //didnt know what this is used for
   BST<T>& operator +=(const BST<T>& rhs){
     functions.tree_add(root,rhs.root);
     return *this;

    }


   private:
   tree_node<T>* root=NULL;
    BST_Functions<T> functions;
};

#endif // BST_H
