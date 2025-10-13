#include "Movable.hpp"
#include <memory>

namespace sfge
{
    Movable::Movable()
    {
    }

    Movable::~Movable()
    {
    }

    void Movable::update(Entity *entity)
    {

    }

    AComponent *Movable::createNew()
    {
        return new Movable();
    }

} //namespace sfge