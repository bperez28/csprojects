#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
   int prev_num(0);//this is the prev number that is always changing at long as there is a new number
   int new_num(1);// new number is (the addition of prev number and new number) total
   int total(1);// total is the addition of prev number and new number
   int new_total(0);// this is adding all the totals together
   int i=0;// a way to get out of the loop is to us i and incument it by one
   int n;// the user in put of how many times the want it to run
   int result;// the end result
   int num;// this is for the user not to get confused so we make the term start from 1 and on
   int size;
    cout<<"initial size of a green crud population (in pounds): "<<endl;
    cin>>size;// population of green crud input
    cout<<" Number of days: "<<endl;// what the user sees
    cin>>n;// user in put of terms it want to do
    num=n/5;// this is to make the program read to start from zero
    if(n<=0){//the if statement is to filter out any negative or zero numbers
        cout<<"must be greater than zero"<<endl;// we cant use zero since zero times anything is always zero
        return 0;
    }
    else{// any number that is postive

    while(i<num){// loop until the users input is met
        total= prev_num+new_num;// total is when the prevous numb and the old total  add
        prev_num= new_num;// the prev number is the old number
        new_num=total;//the total is the new number
        i++;// increase by one everytime it loops
    }
    result=(total)*size;//this is to multiply the fibonacci to the size of the start of the population

    cout<<endl<<"green crud population "<<result<<endl;//print out result

}
    return 0;
}
