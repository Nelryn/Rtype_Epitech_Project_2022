/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Entity.hpp"

class Player : public sfge::Entity {
    public:
        Player();
        ~Player();

        void setTexture();
        sf::CircleShape createBullet(sf::RenderWindow &win);
        void playerShoot(sf::RenderWindow &win, sf::CircleShape bullet);
        void draw(sf::RenderWindow &win);
        //void update();
        sf::Sprite getSprite();
        void gLoop(sf::RenderWindow &win);

    protected:
    private:
        sf::Texture _txt;
        sf::Sprite _sprite;
        int _shoot = 0;
        std::vector<sf::CircleShape> bullets;
};

#endif /* !PLAYER_HPP_ */
