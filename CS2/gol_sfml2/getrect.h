#ifndef GETRECT_H
#define GETRECT_H
#include "gol.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

using namespace sf;

class getrect
{
public:
    getrect();
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape getrect1;

};

#endif // GETRECT_H
