/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** Missile
*/

#include "Missile.hpp"

namespace sfge {

Missile::Missile(sf::Color color, float radius)
{
    this->createMissile(color, radius);
}

Missile::~Missile()
{
}

sf::CircleShape Missile::createMissile(sf::Color color, float radius)
{
    _bullet.setFillColor(color);
    _bullet.setRadius(radius);
    return _bullet;
}

void Missile::updateMissile(sf::RenderWindow &win, float moveX)
{
    for (size_t i = 0 ; i < _bullets.size() ; i++) {
        _bullets[i].move(moveX, 0.f);
        if (_bullets[i].getPosition().x > win.getSize().x) {
            _bullets.erase(_bullets.begin() + i);
        }
    }
}

void Missile::drawMissile(sf::RenderWindow &win)
{
    for (size_t i = 0; i < _bullets.size(); i++) {
        win.draw(_bullets[i]);
    }
}

void Missile::addMissile(sf::Vector2f pos)
{
    _bullet.setPosition(pos);
    _bullets.push_back(_bullet);
}

std::vector<sf::CircleShape> Missile::getListMissile() const
{
    return _bullets;
}

}
