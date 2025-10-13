#include "InputMove.hpp"

int main()
{
    sf::RenderWindow win(sf::VideoMode(800, 600), "r-type");
    sf::Event event;
    sfge::InputShoot input(sf::Keyboard::Space);
    bool press;

    win.setFramerateLimit(60);
    while (win.isOpen()) {
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
            }
            press = input.isMove(event.key);
            //std::cout << press << std::endl;
        }
        win.clear();
        win.display();
    }
    return (0);
}