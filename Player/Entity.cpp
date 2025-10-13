#include "include/Entity.hpp"


namespace sfge
{

Entity::Entity()
{
    //ctor
}

Entity::~Entity()
{
    //dtor
}

void Entity::update()
{
    //update
}

void Entity::draw()
{
    //draw
}

void Entity::setId(unsigned int id)
{
    this->id = id;

}

unsigned int Entity::getId()
{
    return id;
}

} // namespace sfge