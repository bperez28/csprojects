#include "game.h"
#include "constants.h"
#include "gol.h"
#include "getrect.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

getrect::getrect()
{
    getrect1.setPosition(sf::Vector2f(10, 10));
    getrect1.setSize(sf::Vector2f(100, 100));
    getrect1.setFillColor(sf::Color(192, 192,192));
}
void getrect::draw(sf::RenderWindow& window){

   window.draw(getrect1);
}
