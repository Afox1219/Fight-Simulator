#include <SFML/Graphics.hpp>
#include "Exploration.h"

Exploration::Exploration() {
    initializeMap();
}


void Exploration::initializeMap() {
    tileMap = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1}
    };
}

void Exploration::draw(sf::RenderWindow& window){

	for (int y = 0; y < tileMap.size(); ++y) {
		for (int x = 0; x < tileMap[y].size(); ++x) {

			if (tileMap[y][x] == 0) {
				sf::RectangleShape tile(sf::Vector2f(32.f, 32.f));
				tile.setFillColor(sf::Color::Green);
				tile.setPosition(x * 32.f, y * 32.f);
				window.draw(tile);
			}
			else {
				sf::RectangleShape tile(sf::Vector2f(32.f, 32.f));
				tile.setFillColor(sf::Color::Blue);
				tile.setPosition(x * 32.f, y * 32.f);
				window.draw(tile);
			}

		}
	}
}