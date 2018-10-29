#include <iostream>

using namespace std;

int main()
{
    char a=' ';// read the again user input as a charater


    while(a='Y'){//loop if they say yes again

        int num;//number user inputs
        int reminder;//reminder of the now in order number
        int r;// the reminder were the number is backwards
        int backward_num(0);// make the backward number back to int
        int i=0;// make i cout by 1 in loop starting by 0

    cout<<endl<<"Enter an Arabic number: ";//output
    cin>>num;//number
    cout<<endl<<num<<" is ";

    while(num>0){//loop
        r=num%10;//reminder by 10

        num=num/10;//divide by 10
        i++;

        //the number is now in the correct order

    switch(i){//i starts from 1 in the thousands, 2 in hundreds, 3 in tens, 4 in ones.
//switch for the reminder of the backwards number by 10
    case (4): switch(r){ //thousands
            case(1):
                cout<<"M";
                break;
             case(2):
                cout<<"MM";
                break;
             case(3):
                cout<<"MMM";
                break;
             case(4):
                cout<<"MMMM";
                break;
             case(5):
                cout<<"MMMMM";
                break;
            case(6):
                cout<<"MMMMMM";
                break;
             case(7):
                cout<<"MMMMMMM";
                break;
             case(8):
                cout<<"MMMMMMMM";
                break;
             case(9):
                cout<<"MMMMMMMMM";
                break;
        }
        break;

        case (3):   switch(r){   //hundreds
                   case(1):
                       cout<<"C";
                       break;
                   case(2):
                       cout<<"CC";
                       break;
                   case(3):
                       cout<<"CCC";
                       break;
                   case(4):
                       cout<<"CD";
                       break;
                   case(5):
                       cout<<"D";
                       break;
                   case(6):
                       cout<<"DC";
                       break;
                   case(7):
                       cout<<"DCC";
                       break;
                   case(8):
                       cout<<"DCCC";
                       break;
                   case(9):
                       cout<<"CM";
                       break;
       }
           break;

    case(2):    switch(r){   //tens

                   case(1):
                       cout<<"X";
                       break;
                   case(2):
                       cout<<"XX";
                       break;
                   case(3):
                       cout<<"XXX";
                       break;
                   case(4):
                       cout<<"XL";
                       break;
                   case(5):
                       cout<<"L";
                       break;
                   case(6):
                       cout<<"LX";
                       break;
                   case(7):
                       cout<<"LXX";
                       break;
                   case(8):
                       cout<<"LXXX";
                       break;
                   case(9):
                       cout<<"XC";
                       break;
                         }
                     break;

            case (1): switch(r){ //ones
                    case(1):
                        cout<<"I";
                        break;
                     case(2):
                        cout<<"II";
                        break;
                     case(3):
                        cout<<"III";
                        break;
                     case(4):
                        cout<<"IV";
                        break;
                     case(5):
                        cout<<"V";
                        break;
                    case(6):
                        cout<<"VI";
                        break;
                     case(7):
                        cout<<"VII";
                        break;
                     case(8):
                        cout<<"VIII";
                        break;
                     case(9):
                        cout<<"IX";
                        break;
                        }
                    break;

  }
    }
    cout<<" in Roman numerals"<<endl;

    cout<<endl<<"Play again? ";//output
    cin>>a;//again user input

    switch(a){  //switch for user input for again

        case 'Y'://if yes
                break;
    case 'y'://if yes
            break;


         case 'N'://if no get out the program
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
//end of program
