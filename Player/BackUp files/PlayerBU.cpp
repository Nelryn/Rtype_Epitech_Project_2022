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
    txt.loadFromFile("plane.png");
    sf::Sprite sprite;
    sprite.setTexture(txt);
    sprite.setPosition(sf::Vector2f(10,50));
    sprite.scale(2,2);
    //
  
    int shoot = 0;
    sf::Vector2f center;//playercenter

    std::vector<sf::CircleShape> bullets; //many bullets copy of bullet //different position
    while (win.isOpen())
    {

        //PlayerBullet
        
        sf::CircleShape bullet;
        bullet.setFillColor(sf::Color::Green);
        bullet.setRadius(3);
        //bullets.push_back(sf::CircleShape(bullet));
        //bullet.setPosition(70,12);
        //

        //Enemy
        //sf::CircleShape enemy;
        //

        //Event

        sf::Event evt;

        while(win.pollEvent(evt))
        {
            if(evt.type == sf::Event::Closed)
                win.close();
        }
        //

        //Update
        center = sf::Vector2f(sprite.getPosition().x + sprite.getScale().x / 3, sprite.getPosition().y + sprite.getScale().y / 2);
        if (shoot == 3)
        {
            for (size_t i = 0 ; i < bullets.size() ; i++) {
                bullets[i].move(10.f, 0.f);

            // if (bullets[i].getPosition().y < 0)
            //     bullets.erase(bullets.begin() + 1);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //shoot
        {
            bullet.setPosition(center);
            bullets.push_back(sf::CircleShape(bullet));
            shoot = 3;
        }


        ////std::cout << center.x << center.y << std::endl;
        //

        win.clear(sf::Color::Black);
        win.draw(sprite);
        for (size_t i = 0; i < bullets.size(); i++)
            win.draw(bullets[i]);
        win.display();
    }
}

int main()
{
    Player pl;
    pl.setTexture();
}

//get size = rec
//get radius = circle
//fetch boost