#include <iostream>

using namespace std;

int main()
{
    char card_face=' ';
    int card_value;
    int total_value;
    int total_card(0);
    int i=0;

    cout<<"cards on deck: ";
    cin>>card_face;

    switch(card_face){
            case '2':   card_value='2'-'0';

                    break;

            case '3':   card_value='3'-'0';
                    break;
            case '4':   card_value='4'-'0';
                break;
             case '5':   card_value='5'-'0';
                break;
            case '6':   card_value='6'-'0';
                break;
             case '7':   card_value='7'-'0';
                break;
            case '8':   card_value='8'-'0';
                break;
             case '9':   card_value='9'-'0';
                break;
            case 'J':   card_value=10;
                break;
             case 'Q':   card_value=10;
                break;
             case 'K':   card_value=10;
                break;
            case 'A':   card_value=i++;
                break;
            default:   cout<<"Thats not a card";
                 break;
        total_value=total_card +card_value;
        total_card=total_value;
        cout<<total_value<<endl;
    }


    return 0;
}
