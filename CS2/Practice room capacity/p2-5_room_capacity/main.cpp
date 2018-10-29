#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout <<endl<<endl<<endl<< "========================" << endl;
    int capacity=0;
    int attending =0;
    int diff=0;

    //input:
    cout<<"capacity? ";
    cin>>capacity;
    //verify: capacity > 0
    if (capacity <=0){
        cout<<"capacity cant be negative"<<endl;
        return 0;
    }
    cout<<"Attending: ";
    cin>>attending;
    //verify: attending>0
    if (attending <=0){
        cout<<"people attending must be postive"<<endl;
        return 0;
    }

    //attending and capacity cant be negative

    //process:
        //three case:
         //attending > capacity,
        // attending == capacity,
        // attending: capacity >0

    if (attending > capacity){
        diff = attending - capacity;
        cout<<"Too many attendees: Kick out "<<diff<<" people"<<endl;
    }
    else{ //attending <= capacity
        if (attending == capacity){
            diff = 0;
            cout<<"you are at the limit. no more attendees please."<<endl;
        }
        else{
            diff = capacity -attending;
            cout<<"below capacity: you can add "<<diff<<" people"<<endl;
        }

        }


    cout<< endl<<endl<<endl<< "========================="<< endl;
    return 0;

}


