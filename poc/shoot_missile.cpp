#include "InputMove.hpp"
#include "Missile.hpp"

int main()
{
    sf::RenderWindow win(sf::VideoMode(800, 600), "r-type");
    sf::Event event;
    sfge::InputShoot input(sf::Keyboard::Space);
    sfge::Missile missile(sf::Color::Green, 3);
    bool press;

    win.setFramerateLimit(60);
    while (win.isOpen()) {
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
            }
            press = input.isMove(event.key);
            if (press == true)
                missile.addMissile(sf::Vector2f(2, win.getSize().y / 2));
        }
        missile.updateMissile(win, 10.0f);
        win.clear();
        missile.drawMissile(win);
        win.display();
    }
    return (0);
}