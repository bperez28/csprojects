#include <iostream>

using namespace std;

template<class T>
struct node{
    node<T>* next;
    T _item;
    node(T item){
       _item=item;
    }
    friend ostream& operator <<(ostream& outs, node<T>* t){
        outs<<t->_item<<endl;
        outs<<t->next->_item<<endl;
        outs<<t->next->next->_item<<endl;


        return outs;

    }
};

int main()
{
    node<int>* head=NULL;
    node<int>* walker;
//    walker=new node<int>(1);
//    walker->next=head;
//    head=walker;
//    walker= new node<int>(2);
//    walker->next=head;
//    head=walker;
//    walker= new node<int>(3);
//    walker->next=head;
//    head=walker;


    cout<<head;



}
