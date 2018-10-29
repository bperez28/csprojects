#ifndef PROBABILITY_H
#define PROBABILITY_H
#include <iostream>
#include <cstdlib>
using namespace std;


class probability
{
public:
    //num is probability returns if it was posible
    int _prob(int num);
};


 //num is probability returns if it was possible
int probability::_prob(int num){
    //random
          int x=rand()%num;
          //returns if possible
          if(x%num==0){
               return 1;
          }else{
              return 0;
          }
   }


#endif // PROBABILITY_H
