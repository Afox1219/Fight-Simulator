#pragma once

#ifndef EXPLORATION_H
#define EXPLORATION_H

#include <SFML/Graphics.hpp>
#include <vector>

class Exploration {
public:
	 Exploration();
	void draw(sf::RenderWindow& window);




private:
	std::vector<std::vector<int>> tileMap;  // 2D grid for map
	void initializeMap();  // Function to create the map

};
#endif