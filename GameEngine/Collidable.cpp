#include "Collidable.hpp"
#include "Entity.hpp"
#include <iostream>
#include "Movable.hpp"

namespace sfge
{
    Collidable::Collidable()
    {
        //ctor
    }

    Collidable::~Collidable()
    {
        //dtor
    }

    void Collidable::update(Entity *entity)
    {
        //update
        if (entity == nullptr) {
            return;
        }
        if (entity->getId() == 1) {
            std::cout << "Collidable" << std::endl;
        }
        if (this->collide == true) {
            std::cout << "je collide" << std::endl;
            if (entity->hasComponent<Movable>() == true) {
                if (entity->vel.x > 0) {
                    entity->vel.x -= entity->vel.x + 1;
                } else if (entity->vel.x < 0) {
                    entity->vel.x -= entity->vel.x + 1;
                }
                if (entity->vel.y > 0) {
                    entity->pos.y -= entity->vel.y + 1;
                } else if (entity->vel.y < 0) {
                    entity->pos.y += entity->vel.y + 1;
                }
                if (entity->vel.x == 0) {
                    entity->vel.x = -1;
                }
            }
        }
    }

    AComponent *Collidable::createNew()
    {
        return new Collidable();
    }

    void Collidable::setCollide(bool _collide)
    {
        this->collide = _collide;
    }

    bool Collidable::getCollide()
    {
       return collide;
    }
}       // namespace sfge
