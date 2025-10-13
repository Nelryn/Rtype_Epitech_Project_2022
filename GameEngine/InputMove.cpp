/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** InputMove
*/

#include "InputMove.hpp"

namespace sfge {

InputMove::InputMove()
{
    this->setKey(sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Right, sf::Keyboard::Left);
}

InputMove::InputMove(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key right, sf::Keyboard::Key left)
{
    this->setKey(up, down, right, left);
}

InputMove::~InputMove()
{
}

void InputMove::move(sf::Sprite &player, sf::Event::KeyEvent key, float speed)
{
    if (key.code == _up) {
        player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y - speed));
    }
    if (key.code == _down) {
        player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y + speed));
    }
    if (key.code == _right) {
        player.setPosition(sf::Vector2f(player.getPosition().x + speed, player.getPosition().y));
    }
    if (key.code == _left) {
        player.setPosition(sf::Vector2f(player.getPosition().x - speed, player.getPosition().y));
    }
}

void InputMove::setKey(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key right, sf::Keyboard::Key left)
{
    _up = up;
    _down = down;
    _left = left;
    _right = right;
}

//Shoot

InputShoot::InputShoot(sf::Keyboard::Key shoot)
{
    this->setKey(shoot);
}

InputShoot::~InputShoot()
{

}

bool InputShoot::isMove(sf::Event::KeyEvent key)
{
    bool shooter = false;
    if (key.code == _shoot) {
        shooter = true;
    }
    return shooter;
}

void InputShoot::setKey(sf::Keyboard::Key shoot)
{
    _shoot = shoot;
}

}