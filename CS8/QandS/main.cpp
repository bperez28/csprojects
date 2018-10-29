#include <iostream>
#include "Stack.h"
#include "temp.h"

using namespace std;

template<class t>
struct node{
       t _item=NULL;
       node<t>* _next;
       node(const t& item = t(), node<t>* next = NULL):_item(item), _next(next){}
       friend ostream& operator << (ostream& outs, const node<t>& print_me){
           outs<<"["<<print_me->_item<<"]->";
           return outs;
       }
};
 template <class T>
class list{
public:
    //initializes head to NULL
    node<T>* init_head(node<T>* &head){
        head->_item=NULL;
    }

    //deletes all the nodes in the list
    void delete_all(node<T>*&head){

    }

    //true if head is NULL, false otherwise.
    bool empty(const node<T>* head){
        if(head->_item==NULL){
            return true;
        }
        return false;

    }

    //makes a copy of the list, returns a pointer to the last node:
    node<T>* copy_list(const node<T>* head, node<T>* & cpy){

    }

    //insert at the beginning of the list:
    node<T>* insert_head(node<T>* &head, T item){

    }

    //insert_after: if after is NULL, inserts at head
    node<T>* insert_after(node<T>* &head, node<T>* after, const T& item){

    }

    //delete the node at the head of the list, reuturn the item:
    T delete_head(node<T>* &head){

    }

    //print the list and return outs
    ostream& print_list(const node<T>* head, ostream& outs=cout){

    }
};

template<class t>
class q{

public:
    node<t>* next;
    node<t>* head;
    node<t>* temp;
    void push(t item){



      if(head!=temp){
          cout<<"still"<<endl;
          next=new node<t>;
          next->_item=item;
          temp->_next=next;
          temp=temp->_next;
      }else{

          cout<<"start"<<endl;
            next=new node<t>;
            next->_item=item;
            temp=next;
            head=next;


      }

      }




};

int main(int argc, char *argv[])
{
    q<int> Q;
    Q.push(10);
    Q.push(15);
    Q.push(20);
    cout<<"pushed"<<endl<<Q.head->_item<<endl;


}
