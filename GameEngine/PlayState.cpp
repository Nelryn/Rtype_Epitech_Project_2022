#include "PlayState.hpp"

namespace sfge
{
    Playstate::Playstate()
    {
        Core::getInstance()->createEntity("Player");
        Core::getInstance()->idPlayer = EntityManager::getInstance()->getEntities().back()->getId();
    }


    void Playstate::draw(sf::RenderWindow &window)
    {
        AState::draw(window);

        return;
    }

    void Playstate::update()
    {
        AState::update();

        return;
    }
}