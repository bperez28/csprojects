#include <iostream>


using namespace std;
int main()
{

    cout<<endl<<endl<<"=============================="<<endl;

    int total(0);
    int total_b(0);
    char bit=' ';
    int bit_value;
    int dec;
    int r;
    int bin(0);
    int i=1;




//  Binary to Decimal

//  output
   cout<<"binary number: "<<endl;
//  user input
    cin>>bit;

//  loop
    while(bit !='B'){
//  change charter to integer
            bit_value=bit-'0';
            cin>>bit;
//  when adding new number from right side
            total=total*2+bit_value;
            dec=total;
    }
    //  output
             cout<<dec<<endl;


    //  Decimal to binary

             while(dec>0){
//                 get the reminder
                 r=dec%2;
//                 maker number decrease
                 dec=dec/2;

                 bin=bin*10+r;

             }
//             to make it read forward
             while(bin>0){

                 r=bin%10;
                 bin=bin/10;
                 total_b=total_b*10+r;


             }
//             output
            cout<<total_b<<"B";







  cout<< endl<<endl<<"===================="<<endl;
   return 0;
}
