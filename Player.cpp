#include "Player.h"
#include <SFML/Graphics.hpp>

#include "Player.h"

Character::Character() {
    shape.setSize(sf::Vector2f(50.f, 50.f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(400.f, 300.f);

    movespd = 5.f;
    isInCombat = false;  // Default to exploration mode
}

void Character::updateExploration() {
    // Handle movement in exploration mode
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        shape.move(-movespd, 0.f);  // Move left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        shape.move(movespd, 0.f);  // Move right
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        shape.move(0.f, -movespd);  // Move up
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        shape.move(0.f, movespd);  // Move down
    }
}

void Character::updateCombat() {
    // Handle combat actions, e.g., selecting an attack or using an item
    // This can be expanded depending on how you want combat to function
    // Example: Reduce health when attacked or use a special attack
}

void Character::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
