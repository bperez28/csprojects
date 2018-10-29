#include <iostream>

using namespace std;

int main()
{
    char p1=' ';//player 1
    char p2=' ';//player 2
    char a=' ';//characters
    cout<<endl;//space
    while(a='Y'){//loop
    cout<<"Player1:";//output:player1
    cin>>p1;//user input
    cout<<"Player2:";//output:player2
    cin>>p2;//user input
    cout<<endl;
    switch(p1){//switch for player 1
// player1 rock input
    case 'R':   switch(p2){//switch for player 2

                    case 'R'://rock input for player 2
                        cout<<"It's a tie"<<endl;//output
                        break;

                    case 'P'://paper input for player 2
                        cout<<"Player 2 wins"<<endl;//output
                        break;

                    case 'S'://scissors input for player 2
                        cout<<"Player 1 wins"<<endl;
                        break;

                        // if player 2 doesnt pick r,s,p
                    default:
                        cout<<"player 2 incorrect must be: R,P,or S"<<endl;
                        break;
            }
            break;

//     if player 1 picks paper
    case 'P':   switch(p2){
           //if player 2 picks rocks
            case 'R':
                cout<<"Player 1 wins"<<endl;
                break;
           //if player 2 picks paper
            case 'P':
                cout<<"It's a tie"<<endl;
                break;
//            if player 2 picks s
            case 'S':
                cout<<"Player 2 wins"<<endl;
                break;
//            if player 2 doesnt pick r,s,p
            default:
                cout<<"Player 2 incorrect must be: R,P,or S"<<endl;
                break;
    }
            break;

//     if player 1 picks s
    case 'S':   switch(p2){
//            if player 2 picks r
            case 'R':
                cout<<"Player 2 wins"<<endl;
                break;
//            if player 2 picks p
            case 'p':
                cout<<"Player 1 wins"<<endl;
                break;
//            if player 2 picks s
            case 'S':
                cout<<"it's a tie"<<endl;
                break;
//            if player 2 doesnt pick r,s,p
            default:
                cout<<"Player 2 ncorrect must be: R,P,or S"<<endl;
                break;
    }
            break;

//    if player 1 doesnt pick r,s,p
    default:
            cout<<"player 1 incorrect must be: R,P,or S"<<endl;
            break;

    }
    cout<<endl<<"again? ";//output
    cin>>a;
    cout<<endl;
    switch(a){//switch for again

        case 'Y'://if yes
                break;


         case 'N'://if no return 0
        return 0;

            break;

        default:// if incorrect input
            cout<<"incorrect input "<<endl;
            return 0;
            break;
    }
    }

}
