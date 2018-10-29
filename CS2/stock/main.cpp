#include <iostream>

using namespace std;

double stock_value(int whole_num,double nom);//function for stock value
bool stock_valid(int whole_num,int nom,int denom);// to is if the users input is vaild
int main()
{
    cout<<endl<<"---------------------------------------"<<endl;
    double shares;//shares own by user
    int whole_num;// whole number of stock
    int nom;// numorator of the 8th of a dollar
    double value;// value of the stock
    double shares_value;// value of stock determine by how many shares he owns
    int denom;// the denom of the stock value

    cout<<"Number of shares own: ";
    cin>>shares;

    char slash;// the slash the user inputs
    cout<<"stock value (example: 1 1/8): ";
    cin>>whole_num>>nom>>slash>>denom;// for user to input without asking individual

    if(shares<=0){//if invalid share
        cout<<endl<<"Invalid share"<<endl;
        if(stock_valid(whole_num,nom,denom)){

        }
        else{//inside invalid share looking if anything else is as while
            if(whole_num<0){
                cout<<"invalid whole number"<<endl;

            }
            if (nom<0){
                cout<<"negative fraction"<<endl;

            }
            if(denom!=8){
                cout<<"denominator must be 8"<<endl;

            }

            return 0;

         }


    }
    else{// if share is vaild

    if(stock_valid(whole_num,nom,denom)){// valid share continue program and vaild stock input

        value=stock_value(whole_num,nom);//the value of one stock

        shares_value=value*shares;// the value of all the shares
      cout<<endl<<"share value: "<<shares_value<<endl;

    return 0;
    }


   else{// invalid whole number and/or fraction inside vaild share
       if(whole_num<0){
           cout<<"invalid whole number"<<endl;

       }
       if (nom<0){
           cout<<"negative fraction"<<endl;

       }
       if(denom!=8){
           cout<<"denominator must be 8"<<endl;

       }

       return 0;

    }


    }

}
double stock_value(int whole_num,double nom){//the function for the stock value
    double nom_den=nom/8;
    return(whole_num+nom_den);
}
bool stock_valid(int whole_num, int nom, int denom){// the function to see if stock is valid
    if(whole_num<0){
        return false;
    }
    if(nom<0){
        return false;
    }
    if(denom!=8){
        return false;
    }
    return true;
}
