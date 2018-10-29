#include "game.h"
#include "constants.h"
#include "gol.h"
#include "getrect.h"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>


using namespace std;

using namespace sf;

void game::set(int x, int y ){
    _y=y;
    _x=x;
}

game::game()
{
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "GAME OF LIFE!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.
    font.loadFromFile("/Users/Bryan/Dropbox/gol_sfml2/Arial.ttf");

    //    system = System();
    window.setFramerateLimit(5);

//    for(int i=0; i<num_of_text;i++){
//        button.push_back(sf::RectangleShape(sf::Vector2f(text_box_x,text_box_y*i)));
//        button[i].setOutlineThickness(3);
//        button[i].setOutlineColor(sf::Color(102,153,153));

//        text.push_back(sf::Text("",font,35));
//        text[i].setFillColor(sf::Color::White);

//        button[i].setPosition(sf::Vector2f(text_box_y+gap_n_box_s*i,(text_box_y+gap_n_box_s)+box_s*i));
//        text[i].setPosition(sf::Vector2f(text_box_y+gap_n_box_s*i,(text_box_y+gap_n_box_s)+box_s*i));

//    }
//    text[0].setString("PLAY/PAUSE");
//    text[1].setString("RANDOM");
//    text[2].setString("RESET");
//    text[3].setString("LOAD");
//    text[4].setString("SAVE");
//    text[5].setString("ESC");


    mouseIn = true;


  }

void game::run()
{

    int a[m_row][max_col];
    int s[m_row][max_col];
    _init_two_d(a,m_row,m_col);
    b._load(s);


    while (window.isOpen())
    {


        processEvents();
        if(!pause){
            //           cout<<"pause/play"<<endl;
            update(a);

        }
        if(random){
            cout<<"random"<<endl;
            b._random_(a);
            random=!random;

        }
        if(reset){
            cout<<"reset"<<endl;
            _init_two_d(a,m_row,m_col);

            b.pattern(a);
            reset=!reset;

        }
        if(load){
            cout<<"load"<<endl;
            b._load(a);
            _copy_2d(s,a);

            load=!load;


        }
        if(save){
            cout<<"saved"<<endl;
            b._save(a);
            _copy_2d(s,a);
            save=!save;

        }
        if(escape){
            cout<<"out of program"<<endl;
            window.close();
        }
        if(mouseClick){
            cout<<"mouse Clicked"<<endl;
            mouse_click_location(a);
            _mouse_click();


        }

        render(a,s); //clear/draw/display

    }
}

// bools
void game::_pause(){
    pause=!pause;

}
void game::_reset(){
    reset=!reset;
}

void game::_mouse_click(){
    mouseClick=!mouseClick;

}
void game::_load_click(){
    load=!load;
}
void game::_save_click(){
    save=!save;
}
void game::_esc(){
    escape=!escape;
}
void game::_random(){
    random=!random;
}


void game::mouse_click_location(int a[][max_col]){

    int r;//row of boxes
    int c;// col of boxes
    for(int i=0; i<m_col*box_x;i++){
        for(int j=0;j<m_row*box_y;j++){
            if(_x>gap_n_box_s*i+box_x && _x<gap_n_box_s*i+(box_x+gap_n_box_s)){
                c=i;
            }

            if(_y>gap_n_box_s*j+box_y && _y<gap_n_box_s*j+(box_y+gap_n_box_s)){
                r=j;

            }
        }
    }
    //if dead turn alive if alive turn dead
    if(a[r][c]==0){
        a[r][c]=1;
    }
    else{
        a[r][c]=0;
    }

    //if side bar bool when clicked
    int i=0;

    if(_x>text_box_x && _x<text_box_x+text_box_w){
        if(_y>text_box_y && _y<text_box_y+box_s){
            _pause();

        }
    }
    if(_x>text_box_x & _x<text_box_x+text_box_w){
        if(_y>(text_box_y+gap_n_box_s) && _y<(text_box_y+gap_n_box_s)+box_s){

            _random();

        }
    }
    if(_x>text_box_x & _x<text_box_x+text_box_w){
        if(_y>(text_box_y+gap_n_box_s*2) && _y<(text_box_y+gap_n_box_s*2)+box_s){
            _reset();

        }
    }
    if(_x>text_box_x & _x<text_box_x+text_box_w){
        if(_y>(text_box_y+gap_n_box_s*3) && _y<(text_box_y+gap_n_box_s*3)+box_s){

            _load_click();

        }
    }
    if(_x>text_box_x & _x<text_box_x+text_box_w){
        if(_y>(text_box_y+gap_n_box_s*4) && _y<(text_box_y+gap_n_box_s*4)+box_s){

            _save_click();

        }
    }
    if(_x>text_box_x & _x<text_box_x+text_box_w){
        if(_y>(text_box_y+gap_n_box_s*5) && _y<(text_box_y+gap_n_box_s*5)+box_s){
            i++;
            _esc();

        }
    }

}

void game::render(int a[][max_col], int s[][max_col]){
    window.clear();
    Draw(a,s);
    window.display();
}


void game::Draw(int a[][max_col], int s[][max_col]){


    //boxes
    for(int i=0; i<m_col;i++){

        for(int j=0; j<m_row;j++){

            if(a[j][i]==1){
                int col=box_x+(box_s+gap)*i;
                int row=box_y+(box_s+gap)*j;
                //            sf::RectangleShape getrect;
                getrect.setPosition(sf::Vector2f(col,row));
                //box size
                getrect.setSize(sf::Vector2f(box_s,box_s));
                //changes blocks color 192 was the original one its trans
                // 244 is white
                getrect.setFillColor(sf::Color(244, 244,244));
                window.draw(getrect);
            }
            else{
                int col=box_x+(box_s+gap)*i;
                int row=box_y+(box_s+gap)*j;
                sf::RectangleShape getrect;
                getrect.setPosition(sf::Vector2f(col,row));
                //box size
                getrect.setSize(sf::Vector2f(box_s,box_s));
                //changes blocks color 192 was the original one its trans
                //115 is a dark grey
                getrect.setFillColor(sf::Color(115, 115,115));
                window.draw(getrect);
            }


        }

    }

    //side bar
    for(int i=0;i<num_of_text;i++){

        //        sf::RectangleShape getrect;
        getrect.setPosition(sf::Vector2f(m_col*(box_s+gap)+gap*5,text_box_y+(box_s+gap)*i));
        //box size
        getrect.setSize(sf::Vector2f(text_box_w,box_s));
        //changes blocks color 192 was the original one its trans
        //115 is a dark grey
        getrect.setFillColor(sf::Color(31, 75,145));
        window.draw(getrect);

    }




    for(int i=0; i<m_col;i++){

        for(int j=0; j<m_row;j++){

            if(s[j][i]==1){
                int col=small_box_x+(small_box_s+small_box_gap)*i;
                int row=small_box_y+(small_box_s+small_box_gap)*j;
                //            sf::RectangleShape getrect;
                getrect.setPosition(sf::Vector2f(col,row));
                //box size
                getrect.setSize(sf::Vector2f(small_box_s,small_box_s));
                //changes blocks color 192 was the original one its trans
                // 244 is white
                getrect.setFillColor(sf::Color(244, 244,244));
                window.draw(getrect);
            }
            else{
                int col=small_box_x+(small_box_s+small_box_gap)*i;
                int row=small_box_y+(small_box_s+small_box_gap)*j;
                sf::RectangleShape getrect;
                getrect.setPosition(sf::Vector2f(col,row));
                //box size
                getrect.setSize(sf::Vector2f(small_box_s,small_box_s));
                //changes blocks color 192 was the original one its trans
                //115 is a dark grey
                getrect.setFillColor(sf::Color(115, 115,115));
                window.draw(getrect);
            }
        }




    }


    window.draw(getrect);

}

void game::processEvents()
{

    sf::Event event;
    float mouseX, mouseY;

    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;

            // key pressed
        case sf::Event::KeyPressed:
            switch(event.key.code){
            case sf::Keyboard::Left:
                command = 4;
                break;
            case sf::Keyboard::Right:
                command = 6;
                break;

            case sf::Keyboard::Escape:
                window.close();

                break;
            case sf::Keyboard::P:
                _pause();
                break;

            }

            break;
        case sf::Event::MouseEntered:
            mouseIn = true;
            break;

        case sf::Event::MouseLeft:
            mouseIn = false;
            break;

        case sf::Event::MouseMoved:
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;
            break;

        case sf::Event::MouseButtonReleased:

            if (event.mouseButton.button == sf::Mouse::Right || event.mouseButton.button == sf::Mouse::Left )
            {
                _mouse_click();
//                std::cout << "Button: (" << event.mouseButton.x << ", "
//                          << event.mouseButton.y << ")"<<std::endl;
                _x = event.mouseButton.x;
                _y = event.mouseButton.y;

            }

            break;

        default:
            break;
        }
    }

}


void game::update(int a[][max_col]){

    g.check_around_8(a);

}


