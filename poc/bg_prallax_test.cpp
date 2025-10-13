/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** main
*/

#include "bg.hpp"
#include <iostream>

using namespace sfge;

int main(void)
{
    sf::RenderWindow w(sf::VideoMode(800, 600), "PARALLAX");
    sf::Clock clock;

    Parallax bg;

    while (w.isOpen()) {
        sf::Event event;
        while(w.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                w.close();
        }
        sf::Time time;
        float tempo = 0.10;
        float seconds;

        time = clock.getElapsedTime();
        seconds = time.asMicroseconds() / 1000000.0;
        if (seconds > tempo) {
            bg.animateParallax();
            clock.restart();
        }

        w.clear(sf::Color::Black);
        bg.draw(w);
        w.display();
    }
    return 0;
}

