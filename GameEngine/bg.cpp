#include "bg.hpp"

namespace sfge {
    Parallax::Parallax()
    {
        std::vector<std::string> bgs = {BG1, BG2, BG3, BG4};
        _vel = {0, 1, 2, 4};
        for (auto bg : bgs) {
            sf::Texture texture;

            if (!texture.loadFromFile(bg))
                exit(84);
            _txtureTab.push_back(std::make_shared<sf::Texture>(texture));
        }
        for (std::vector<std::shared_ptr<sf::Texture>>::iterator it = _txtureTab.begin();
            it != _txtureTab.end(); it++) {
            (*it)->setRepeated(true);
             _spriteTab.push_back(std::make_shared<sf::Sprite>(sf::Sprite(*(*it).get())));
        }
        for (std::vector<std::shared_ptr<sf::Sprite>>::iterator it = _spriteTab.begin();
            it != _spriteTab.end(); it++) {
            (*it)->setPosition(sf::Vector2f(0, 0));
            (*it)->setScale(sf::Vector2f(3.2, 3.2));
        }
    }

    Parallax::~Parallax()
    {
    }

    void Parallax::draw(sf::RenderWindow &w)
    {
        for (auto &sprite : _spriteTab)
            w.draw(*sprite);
    }

    void Parallax::animateParallax()
    {
        int index = 0;
        for (std::vector<std::shared_ptr<sf::Sprite>>::iterator it = _spriteTab.begin();
            it != _spriteTab.end(); it++) {
            sf::IntRect rect = (*it)->getTextureRect();
            rect.left += _vel.at(index);
            (*it)->setTextureRect(rect);
            index++;
        }
    }
}