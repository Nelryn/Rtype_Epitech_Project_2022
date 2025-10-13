#include "InputMove.hpp"

int main()
{
    sf::RenderWindow win(sf::VideoMode(800, 600), "r-type");
    sf::Event event;
    sfge::InputMove input(sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Right, sf::Keyboard::Left);
    sf::Texture tx;
    sf::Sprite sprite;

    tx.loadFromFile("./sprite.png");
    sprite.setTexture(tx);
    sprite.scale(sf::Vector2f(2.0, 2.0));
    win.setFramerateLimit(60);
    while (win.isOpen()) {
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
            }
            input.move(sprite, event.key, 100);
        }
        win.clear();
        win.draw(sprite);
        win.display();
    }
    return (0);
}