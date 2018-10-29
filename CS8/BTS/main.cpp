#include <iostream>
#include"bst_functions.h"
#include "bst.h"
#include "avl.h"
using namespace std;

int main()
{
    bool out=false;
    char input;
    avl<int> b ;
    int val;
    while(!out){
// [R]andom  [I]nsert  [C]clear  [S]earch  [E]rase   e[X]it:
        cout<<" [R]andom ";
        cout<<" [I]nsert ";
        cout<<" [C]clear ";
        cout<<" [S]earch ";
        cout<<" [E]rase ";
        cout<<" e[X]it: ";
        cin>>input;
        switch(input){
        case 'R':
        case 'r': val = rand() % 100;
            cout<<"-- Inserting "<<val<<endl;
                 b.insert(val);
            break;
        case 'I':
        case 'i':cout<<"?";
                cin>>val;
                cout<<"-- Inserting "<<val<<endl;
                     b.insert(val);
            break;
        case 'C':
        case 'c':
            b.clear();
            break;
        case 'S':
        case 's':cout<<"?";
                cin>>val;

                if(b.search(val)){
                    cout<<"Item found"<<endl;
                }else{
                          cout<<"Item not found"<<endl;
                }
            break;
        case 'E':
        case 'e':cout<<"?";
            cin>>val;

            if(b.erase(val)){
              cout<<"-- Erasing "<<val<<endl;
            }else{
                cout<<"item not found"<<endl;
            }
            break;
        case 'X':
        case 'x':out=true;
            break;
        default: cout<<"wrong input"<<endl;
            break;

        }

        if(!b.rootisnull()){          
        cout<<b;
        }
    }



    cout<<endl;
}
