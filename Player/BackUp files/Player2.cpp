/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** Player
*/

#include "Player.hpp"

Player::Player()
{
}

Player::~Player()
{
}

void Player::setTexture()
{
    sf::RenderWindow win(sf::VideoMode(800, 600), "Shooter");
    win.setFramerateLimit(60);

    //Player
    sf::Texture txt;
    txt.loadFromFile("Img/plane.png");
    sf::Sprite sprite;
    sprite.setTexture(txt);
    sprite.setPosition(sf::Vector2f(10,50));
    sprite.scale(2,2);
    //
  
    int shoot = 0;
    sf::Vector2f center;//playerCenter

    std::vector<sf::CircleShape> bullets;
    
    sf::CircleShape bullet;
    bullet.setFillColor(sf::Color::Green);
    bullet.setRadius(3);
    
    while (win.isOpen())
    {
        sf::Event evt;

        while(win.pollEvent(evt))
        {
            if(evt.type == sf::Event::Closed)
                win.close();
        }

        center = sf::Vector2f(sprite.getPosition().x + (sprite.getTexture()->getSize().x / 2), sprite.getPosition().y + (sprite.getTexture()->getSize().y / 2) + 35.f); //set sprite center 
        
        for (size_t i = 0 ; i < bullets.size() ; i++) {
            bullets[i].move(10.f, 0.f);

            if (bullets[i].getPosition().x > win.getSize().x) {
                bullets.erase(bullets.begin() + i);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            bullet.setPosition(center);
            bullets.push_back(sf::CircleShape(bullet));
            shoot = 3;
        }

        win.clear(sf::Color::Black);
        win.draw(sprite);
        for (size_t i = 0; i < bullets.size(); i++)
            win.draw(bullets[i]);
        win.display();
    }
}

int main()
{
    Player player;
    player.setTexture();
}

//player herite entity / enemy herite entity