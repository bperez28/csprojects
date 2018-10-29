#include <iostream>

using namespace std;

int main()
{
    int n;//number of cards
    float card_values=' ';'2';'3';'4';'5';'6';'7';'8';'9';'10';// card values of everything except face cards
   float face_card_value=' ';// face cards values are Jokers, queen, king and Ace
   char cards=' ';
    int i;// amount of cards drawed

    cout<<endl<<"how many cards do you have? ";
    cin>>n;

    cout<<endl<<"face cards? ";
    cin>>face_card_value;
    cout<<face_card_value;


    cout<<endl<<"card values? ";
    cin>>card_values;
    cout<<card_values;

    cards=face_card_value+card_values;
    cout<<cards;

    while(i>=5){
        switch(cards){
        case 'k':
            break;
        }

    }
    if(i<2){
        cout<<"insufficient amount of cards"<<endl;
    }
    else{


    }












    return 0;
}
