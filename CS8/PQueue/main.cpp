#include <iostream>
#include "pqueue.h"
#include "heap.h"
using namespace std;
void Test_heap();
int main()
{
//    PQueue<int> pq;
//        for (int i = 0; i<100; i++){
//            pq.insert(Random(1,1000), Random(1,10));
//        }
//       cout<<pq;
    Test_heap();
}
void Test_heap(){
   Heap<int> h;
   h.insert(8);
   h.insert(10);

//   cout<<h;
   while(!h.is_empty()){
       cout<<"removing"<<endl;
      int removing_item= h.Pop();
      cout<<removing_item<<endl;
   }

}
