#include <iostream>

using namespace std;

int main()
{
    //the variables
    double n=0,r=0,guess=0,new_guess=0,distance=0;
    //n= user input
    //r= n/guess
    //guess =n/2
    //new guess= (guess+r)/2

    //space out
    cout<<endl<<"======================================"<<endl;

    //user input
    cout<<endl<<endl<<"Pick a number to take the square root: "<<endl;
          cin>>n;
    if(n<0){
        cout<<"square root of a number can't be negative!"<<endl;
    }
    else{//guess by using user input divided by 2
    guess = n/2;

    //get r by user input divided by the guess
    r = n/guess;

    //new guess by getting the sum of guess and r
    //than divide the whole thing by 2
    new_guess=(guess +r)/2;

    //to verify if the distace between outcome is near 0.01
    distance = guess - new_guess;

    //loop
    while(distance>0.01){

   new_guess = guess;
   r = n/ new_guess;
   guess=(new_guess +r)/2;
   distance = new_guess -guess;
    }

    //output
    cout<<endl<<"square root: "<<guess<<endl;


    return 0;

}
}
