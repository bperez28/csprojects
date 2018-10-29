#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <iostream>
using namespace std;

template<typename T>
class tree_node
{
public:
    tree_node();
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;
    int _height;
    int _max_height;

    int height(){
        int l, r;
        if(_left==NULL){
            l=-1;
        }else{
            l=_left->_height;
        }
        if(_right==NULL){
            r=-1;
        }else{
            r=_right->_height;
        }
        _max_height=1+max(l,r);
        return _max_height;
        // Height of a node is 1 + height of the "taller" child
        //A leaf node has a height of zero: 1 + max(-1,-1)
    }
    int update_height(){

        _height=height();

        //set the _height member variable (call height();)
    }

    tree_node(T item=T(), tree_node* left=NULL,
                          tree_node* right=NULL):
                    _item(item), _left(left), _right(right)
    {
        update_height();
        //don't forget to set the _height.
    }
    friend ostream& operator <<(ostream& outs,
                                const tree_node<T>& t_node){
//        outs<<"|"<<t_node._item<<"|";

    }
};

#endif // TREE_NODE_H
