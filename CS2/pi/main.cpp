#include <iostream>

using namespace std;

int main()
{
    int i=0;//make i start from 0
    int r;//r= the reminder when divided by 2
    int n;// user input number of terms
    double term;//terms is -1^r/2i+1
    double new_t(0);//add terms together in loop
    double pi;//end result
    double num;//numurator
    double den;//denominator

    cout<<"term: ";//output
    cin>>n;//user in put terms
        for(i=0;i<n;i++){//loop
             r=i%2;//reminder when divided by 2
            switch(r){
                case 1: r=-1;//if reminder is 1
                     break;
                 case 0: r=1;//if reminder is 0
                     break;
             }//out of switch

        num= 1*r;//numurator
        den=2*i+1;//denominator
        term=num/den;//terms is -1^r/2i+1
        new_t=new_t+term;//add terms together in loop
    }//out of the loop

    pi=4.0*new_t;//multiply 4 since i factored it out before the loop
     cout<<pi<<endl;//output
    return 0;
}

