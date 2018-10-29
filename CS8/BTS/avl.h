#ifndef AVL_H
#define AVL_H
#include "bst_functions.h"
#include <ostream>
using namespace std;

template <typename T>
class avl
{
public:
    avl(){
    }
     avl(const T* sorted_list, int size=-1){
         size--;
         root  = functions.tree_clear(root);
         root = functions.tree_from_sorted_list(sorted_list,0,size);
     }

     //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

     avl(const avl<T>& copy_me){
         root  = functions.tree_clear(root);
         root = functions.tree_copy(copy_me.root);
     }

     avl<T>& operator =(const avl<T>& rhs){
         if(root!=rhs.root){
           functions.tree_clear(root);
           root = functions.tree_copy(rhs.root);
           return *this;
         }
     }


     //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

     void insert(const T& insert_me){
            functions.avl_tree_insert(root,insert_me);
     }

    bool erase(const T& target){
       return functions.avl_tree_erase(root,target);

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

     friend ostream& operator <<(ostream& outs, avl<T>& tree){
        tree.functions.tree_print(tree.root,tree.root->_height,outs);

     }

     avl<T>& operator +=(const avl<T>& rhs){
         functions.tree_add(root,rhs.root);
         return *this;
     }

    private:
     BST_Functions<T> functions;
     tree_node<T>* root=NULL;
};

#endif // AVL_H
