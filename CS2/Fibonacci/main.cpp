#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    char a=' ';// read the again user input as a charater

 while(a='Y'){//loop if they say yes again

   int prev_num(0);//this is the prev number that is always changing at long as there is a new number
   int new_num(1);// new number is (the addition of prev number and new number) total
   int total(1);// total is the addition of prev number and new number
   int i=0;// a way to get out of the loop is to us i and incument it by one
   int n;// the user in put of how many times the want it to run
   int num;// this is for the user not to get confused so we make the term start from 1 and on

        cout<<" Please enter a number: ";// what the user sees
        cin>>n;// user in put of terms it want to do
        cout<<endl<<"The first "<<n<<" Fibonacci number are:"<<endl;

        num=n;// this is to make the program read to start from zero

            if(n<=0){//the if statement is to filter out any negative or zero numbers
                cout<<"must be greater than zero"<<endl;// we cant use zero since zero times anything is always zero
              return 0;
         }
            else{// any number that is postive

                while(i<num){// loop until the users input is met

                      cout<<total<<" ";//the out put of the Fibonacci number

                     total= prev_num+new_num;//total is prevous and old total added together


                      prev_num= new_num;// prevous is old number

                     new_num=total;// new number is old total

                      i++;// counting how many times its in the loop


                 }

            }
        cout<<endl<<"again? ";//output
        cin>>a;//again user input

        switch(a){  //switch for user input for again

            case 'Y':
            case'y'://if yes
                break;


            case 'N':
            case'n'://if no get out the program
              cout<<endl;
                return 0;

                break;

         default:// if number is anything other than Y or N than say incorrect input
            cout<<"incorrect input "<<endl;
            return 0;
            break;
         }
     }
}

