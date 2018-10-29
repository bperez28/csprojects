#ifndef RATIONAL_H
#define RATIONAL_H


class rational
{
public:
     rational(int a, int b);
     //holds two arguments a for numerator and b for denominator
    rational();
    //empty
    friend rational operator +(const rational &a, const rational &b);
    //overloads + to add rationals
    friend rational operator -(const rational &a, const rational &b);
    //overloads - to sub tract rational
    friend rational operator *(const rational &a, const rational &b);
    //overloads * to multiply rations
    friend rational operator /(const rational &a, const rational &b);
    //overloads / to divides rations
    friend rational operator <(const rational &a, const rational &b);
    //overloads right side greater than to read rationals
    friend rational operator >(const rational &a, const rational &b);
    //overloads left side greater than to read rationals
    friend rational operator ==(const rational &a, const rational &b);
    //overloads == to read rationals to compare if they are equal to each other
    rational greater(const int &n1, const int &d1, const int &n2, const int &d2 );
    //this function returns two arguments and is used for both left and right greater than overload
    void g_output();
    //output for greater than weathher its true or false
    void r_input();
    //inputs a rational number if user decides to change when asked
   void r_output();
   //outputs rational number n/d




private:
    int _n;
    //numerator
    int _d;
    //denominator
};
void add_r(const int &n1, const int &d1, const int &n2, const int &d2, int &nn, int & nd);
//function that adds both rationas and passes by reference the new rational used for + overload
void sub_r(const int &n1, const int &d1, const int &n2, const int &d2, int &nn, int & nd);
//function that subtracts both rationas and passes by reference the new rational used for - overload
void multi_r(const int &n1, const int &d1, const int &n2, const int &d2, int &nn, int & nd);
//function that multiplies both rationas and passes by reference the new rational used for * overload
void div_r(const int &n1, const int &d1, const int &n2, const int &d2, int &nn, int & nd);
//function that divides both rationas and passes by reference the new rational used for / overload
bool equal(const int &n1, const int &d1, const int &n2, const int &d2 );
//this is a booleen expression to determain weather both rations are equal to each other used for == overload
void report( rational a, rational b);
//this does the math using the overloads and prints out the results
char get_choice();
//this asks user if they want to change an input or exist from the program




#endif // RATIONAL_H
