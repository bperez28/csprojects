#include <iostream>

using namespace std;

int main()
{
    cout<<endl<<endl<<"==================="<<endl;
    //variables
    int sum =0;
    int number =0;
    int x=0;
    int neg_t=0;
    int pos_t=0;
    int neg1=0;
    int pos1=0;
    //loop
    while(x<10){
        x++;
    //output
        cout<<"number: ";
   //user input
        cin>>number;
        sum =sum+number;

        if(number>=0){
        pos1+=number;
        //total pos
        pos_t=pos1/number;
        }

        //other than pos
        else{

        //neg numbers
        if(number<=0){
           neg1-=number;
           //total neg
           neg_t=neg1/number;
            }
         }
     }

    //result
    cout<<"total positives: "<<pos_t<<endl;
    cout<<"total negatives: "<<neg_t<<endl;
    cout<<"grand total: "<<sum<<endl;

    return 0;
}


