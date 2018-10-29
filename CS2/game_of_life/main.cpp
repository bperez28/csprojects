#include <iostream>
#include "mygol.h"

using namespace std;

int main()
{

    int a[max_row][max_col];
    // initiulizes with 0s
    _init_two_d(a,max_row,max_col);

    //p is the starting position
    mygol p;
    //set is the postion of coordinate being hold to an object
    p.set(0,0);
    // this i will be used to get out of the while loop
    int i=0;
    //load adds ones in the postions given in program
    p.load(a);

    while(i>-1){
        //i is 0 till check_around_8 return a -1 to get out of loop
        //prints array
        p.print_2d_array(a);
        //check_arounf_8 does all the work and calls functions with in it adds up all neighbors moves postion to the next one
        //and replaces valuse of postion if it condtions are ment or not
   i=p.check_around_8(a);

    }

}
