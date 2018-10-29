#include "rational.h"
#include <iostream>

using namespace std;
rational::rational()
{
//empty
}
rational::rational(int a, int b){
    //holds two arguments a for numerator and b for denominator
    _n=a;
    _d=b;
}
rational operator +(const rational &a, const rational &b){
        //overloads + to add rationals
    rational add;
    add_r(a._n,a._d,b._n,b._d,add._n,add._d);
    //function that adds both rationas and passes by reference the new rational used for + overload
    return add;

}

rational operator -(const rational &a, const rational &b){
    //overloads - to sub tract rational
    rational sub;
    sub_r(a._n,a._d,b._n,b._d,sub._n,sub._d);
    //function that subtracts both rationas and passes by reference the new rational used for - overload
    return sub;
}

rational operator *(const rational &a, const rational &b){
    //overloads * to multiply rations
    rational multi;
    multi_r(a._n,a._d,b._n,b._d,multi._n,multi._d);
    //function that multiplies both rationas and passes by reference the new rational used for * overload
    return multi;
}

 rational operator /(const rational &a, const rational &b){
      //overloads / to divides rations
     rational div;
     div_r(a._n,a._d,b._n,b._d,div._n,div._d);
     //function that divides both rationas and passes by reference the new rational used for / overload
     return div;

 }

rational operator <(const rational &a, const rational &b){
     //overloads right side greater than to read rationals
    rational n;
    n.greater(b._n,b._d,a._n,a._d);
     //this function returns two arguments and is used for both left and right greater than overload
    return n;


}

rational operator >(const rational &a, const rational &b){
     //overloads left side greater than to read rationals
    rational n;
    n.greater(a._n,a._d,b._n,b._d);
     //this function returns two arguments and is used for both left and right greater than overload
    return n;


}


 rational operator ==(const rational &a, const rational &b){
     //overloads == to read rationals to compare if they are equal to each other
     if(equal(a._n,a._d,b._n,b._d)){
     //this is a booleen expression to determain weather both rations are equal to each other used for == overload
         return a;
     }
  else{
         rational n(0,0);
         return n;


  }


 }
  void rational::g_output(){
      //output for greater than and also equal to
      int num;
      num=_n+_d;
      //this is cuz i made both num and den 0 if its false for greater than or equal
      if(num==0){

          cout<<"false";
      }
      else{
          cout<<"true";
      }
  }


void rational::r_input(){
    //input to change rational when asked whuch to change
    int n;
    //num
    int d;
    //den
    char c;
    //holds the /

    cout<<"rational number: ";
    cin>>n>>c>>d;
    //private variables
    _n=n;
    _d=d;

}

void rational::r_output(){
    //output rational number in order
    cout<<_n<<"/"<<_d;

}

rational rational::greater(const int &n1, const int &d1, const int &n2, const int &d2){
        //this function returns two arguments and is used for both left and right greater than overload
    int n;
    int s;
    int t;
    n=n1*d2;
    s=n2*d1;
    t=n-s;

      if(t>0){
         _n=n1;
         _d=n1;
      }
      else{
          //if its false
          _n=0;
          _d=0;

      }

}

bool equal(const int &n1, const int &d1, const int &n2, const int &d2 ){
    //this is a booleen expression to determain weather both rations are equal to each other used for == overload

    //to determine if its greater since == operator arent overloaded yet
    int n;
    int s;
    int t;
    n=n1*d2;
    s=n2*d1;
      if(n==s){
          return true;
      }
      else{
          return false;
      }

}

void add_r(const int &n1, const int &d1, const int &n2, const int &d2, int &nn, int & nd){
    //function that adds both rationas and passes by reference the new rational used for + overload
    if(d1==d2){
        //this is if denominators are equal to each other i dont have to cross multiply
        nn=n1+n2;
        //adding nemorators to make new nomurator
        nd=d1;
        //could have made the new denominator equal to any cuz they both equal to each other
    }
    else{
        // if the denominators dont equal
        nd=d1*d2;
        //new den by multiping both old ones
        nn=(n1*d2)+(n2*d1);
        //new num by multiplyin the first num to the second den and vice versa and adding them
    }


}

void sub_r(const int &n1, const int &d1, const int &n2, const int &d2, int &nn, int & nd){
    //function that subtracts both rationas and passes by reference the new rational used for - overload
    if(d1==d2){
        //this is if denominators are equal to each other i dont have to cross multiply
        nn=n1-n2;
        //subtracting nemorators to make new nomurator
        nd=d1;
        //could have made the new denominator equal to any cuz they both equal to each other
    }
    else{
        // if the denominators dont equal
        nd=d1*d2;
        //new den by multiping both old ones
        nn=(n1*d2)-(n2*d1);
        //new num by multiplyin the first num to the second den and vice versa and adding them
    }

}

void  multi_r(const int &n1, const int &d1, const int &n2, const int &d2, int &nn, int & nd){
    //function that multiplies both rationas and passes by reference the new rational used for * overload
    nn=n1*n2;
    //new num by multiping first num to second num
    nd=d1*d2;
     //new den by multiping first den to second den


}

void div_r(const int &n1, const int &d1, const int &n2, const int &d2, int &nn, int & nd){
    //function that divides both rationas and passes by reference the new rational used for / overload
    nn=n1*d2;
    //new num by multiping first num to second dem
    nd=d1*n2;
    //new den by multiping first den to second num


}
void report(rational a, rational b){
   //this does the math using the overloads and prints out the results
    rational added;
    rational sub;
    rational div;
    rational multi;
    rational greaterl;
    rational greaterr;
    rational greatere;

    //using overloaded operators
    added= a+b;
    sub= a-b;
    multi= a*b;
    div= a/b;
    greaterl=a>b;
    greaterr=a<b;
    greatere=a==b;

    //show user the rationals
    cout<<endl;
    cout<<"[1]:";
    a.r_output();
   cout<<endl;
   cout<<"[2]:";
    b.r_output();
    cout<<endl;



    //show user adding of rationals
    cout<<endl;
    a.r_output();
    cout<<" + ";
    b.r_output();
     cout<<" = ";
    added.r_output();
    cout<<endl;

    //show user subtracting of rationals
    a.r_output();
    cout<<" - ";
    b.r_output();
     cout<<" = ";
    sub.r_output();
    cout<<endl;

    //show user multiplication of rationals
    a.r_output();
    cout<<" * ";
    b.r_output();
    cout<<" = ";
    multi.r_output();
    cout<<endl;

    //show user dividing of rationals
    a.r_output();
    cout<<" / ";
    b.r_output();
     cout<<" = ";
    div.r_output();
    cout<<endl;

    //show user greater than true or false
    a.r_output();
    cout<<" > ";
    b.r_output();
    cout<<"  ";
    greaterl.g_output();
    cout<<endl;

    //show user greater than true or false
    a.r_output();
    cout<<" < ";
    b.r_output();
    cout<<"  ";
    greaterr.g_output();
    cout<<endl;

    //show user true or false if rationals equal each other
    a.r_output();
    cout<<" == ";
    b.r_output();
    cout<<" ";
    greatere.g_output();
    cout<<endl<<endl;




}

char get_choice(){
//this asks user if they want to change an input or exist from the program
    char c;
    cout<<"[1] [2] [x]"<<endl;
    cin>>c;
    return c;

}

