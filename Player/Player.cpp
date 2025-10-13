/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** Player
*/

#include "include/Player.hpp"

Player::Player()
{
}

Player::~Player()
{
}

void Player::setTexture()
{
    _txt.loadFromFile("Img/plane.png");
    _sprite.setTexture(_txt);
    _sprite.setPosition(sf::Vector2f(10,50));
    _sprite.scale(2,2);
}

sf::CircleShape Player::createBullet(sf::RenderWindow &win)
{ 
    sf::CircleShape bullet;
    bullet.setFillColor(sf::Color::Green);
    bullet.setRadius(3);
    return bullet;
}

void Player::playerShoot(sf::RenderWindow &win, sf::CircleShape bullet)
{
    sf::Vector2f center;//playerCenter
    center = sf::Vector2f(_sprite.getPosition().x + (_sprite.getTexture()->getSize().x / 2), _sprite.getPosition().y + (_sprite.getTexture()->getSize().y / 2) + 35.f); //set sprite center
    
    if (bullets.size() > 0)
    {
        //std::cout << bullets[0].getPosition().x << std::endl;
    }
    //std::cout << bullets.size() << std::endl;
    for (size_t i = 0 ; i < bullets.size() ; i++) {
        bullets[i].move(10.f, 0.f);

        if (bullets[i].getPosition().x > win.getSize().x) {
            bullets.erase(bullets.begin() + i);
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        bullet.setPosition(center);
        bullets.push_back(bullet);
        //std::cout << bullets.size() << std::endl;
        _shoot = 3;
    }
}

void Player::draw(sf::RenderWindow &win)
{    

    for (size_t i = 0; i < bullets.size(); i++) {
        win.draw(bullets[i]);
    }
    win.draw(_sprite);
}

void Player::gLoop(sf::RenderWindow &win)
{
    setTexture();
    win.setFramerateLimit(60);
    while (win.isOpen())
    {
        sf::Event evt;

        while(win.pollEvent(evt))
        {
            if(evt.type == sf::Event::Closed)
                win.close();
        }
        sf::CircleShape bullet = createBullet(win);
        playerShoot(win, bullet);
        win.clear(sf::Color::Black);
        draw(win);
        win.display();
    }
}

sf::Sprite Player::getSprite()
{
    return _sprite;
}

// void Player::update()
// {

// }

int main()
{
    sf::RenderWindow win(sf::VideoMode(800, 600), "Shooter");
    std::vector<sf::CircleShape> bullets;
    Player player;
    player.gLoop(win);
}

//player herite entity / enemy herite entity