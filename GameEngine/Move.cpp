#include "Move.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Entity.hpp"
#include "Core.hpp"


namespace sfge
{
    Move::Move()
    {
    }

    Move::~Move()
    {
    }

    void Move::update(Entity *ent)
    {
        if (int(ent->getUid()) == int(Core::getInstance()->_clientUdp->getId())) {
            //std::cout << "entity Id: " << int(ent->getId()) << std::endl;
            //std::cout << "my Id: " << int(Core::getInstance()->_clientUdp->getId()) << std::endl;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == false &&
                sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == false) {
                ent->vel.x = 0;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                ent->vel.x = -1;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                ent->vel.x = 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == false) {
                ent->vel.y = 0;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                ent->vel.y = -1;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                ent->vel.y = 1;
            }
        } else {
            std::cout << "that's not me !!" << std::endl;
        }
    }

    AComponent *Move::createNew()
    {
        return new Move();
    }
}