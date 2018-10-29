#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "gol.h"
#include "constants.h"

class game
{
public:
    game();
    void Draw(int a[][max_col], int s[][max_col]);
    void run();
    void set(int x, int y );
    void processEvents();
    void update(int a[][max_col]);
    void render(int a[][max_col], int s[][max_col]);
    void _pause();
    void _mouse_click();
    void _reset();
    void mouse_click_location(int a[][max_col]);
     void _load_click();
      void _save_click();
      void _esc();
      void _random();

private:
    sf::RenderWindow window;
  sf::RectangleShape getrect;
    sf::CircleShape mousePoint;
    sf::RectangleShape sideBar;
    std::vector<sf::RectangleShape> button;
    std::vector<sf::Text> text;
    vector<string> items;
    int command;
    sf::Font font;
    sf::Text myTextLabel;
    bool mouseIn;
    bool pause=true;
    bool mouseClick;
    bool reset;
    bool load;
    bool save;
    bool escape;
    bool random;
    gol g;
    gol b;
    int _x=0;
    int _y=0;
//    sf::Font font;
//    sf::Text text;

};


#endif // GAME_H
