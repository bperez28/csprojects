#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;

int main()
{
    Queue<int> q;
    q.push(10);
    cout<<endl<<"push"<<endl;
    cout<<q;
    q.push(20);
    cout<<endl<<"push"<<endl;
     cout<<q;
    q.push(30);
    cout<<endl<<"push"<<endl;
    cout<<q;
    q.push(40);
    cout<<endl<<"push"<<endl;
     cout<<q;
     cout<<endl<<"pop"<<endl;
     q.pop();
     q.pop();
     q.pop();
     cout<<q;


    cout<<endl<<"empty"<<q.empty()<<endl;
    cout<<endl<<"Next to be Removed: "<<q.top()<<endl;
    cout<<endl<<endl;;

    Stack<int> s;
    s.push(10);
    s.push(20);
    cout<<endl;
    cout<<s;
    s.push(30);
    cout<<endl<<"push"<<endl;
    cout<<s;
    s.push(40);
     cout<<endl<<"push"<<endl;
     cout<<s;
     cout<<endl<<"pop"<<endl;
     s.pop();
     cout<<s;
     cout<<endl<<"pop"<<endl;
      s.pop();
      cout<<s;

    cout<<endl<<"empty"<<s.empty()<<endl;
    cout<<endl<<"Next to be Removed: "<<s.top()<<endl;

    cout<<endl;
    return 0;
}
