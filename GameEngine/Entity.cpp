#include "Entity.hpp"
#include "Core.hpp"

namespace sfge
{

Entity::Entity()
{
    //this->old.x = 0;
    //this->old.y = 0;
}

Entity::~Entity()
{
    //dtor
}

void Entity::update()
{
    //update
    for (auto &it : this->_m_components) {
        it.second->update(this);
    }
    this->pos.x += this->vel.x;
    this->pos.y += this->vel.y;
    this->sprite.setPosition(this->pos.x, this->pos.y);
}

void Entity::draw(sf::RenderWindow &window)
{
    //draw
    window.draw(sprite);
    sf::RectangleShape rect(sf::Vector2f(this->size.x, this->size.y));
    rect.setPosition(this->pos.x, this->pos.y);
    // std::cout << this->pos.x << " : " << this->pos.y << std::endl;
    rect.setFillColor(sf::Color(255, 0, 0, 100));
    window.draw(rect);
}

void Entity::setId(unsigned int id)
{
    this->id = id;

}

unsigned int Entity::getId() const
{
    return id;
}

void Entity::setUid(unsigned char uid)
{
    this->_uid = uid;
}

unsigned char Entity::getUid() const
{
    return this->_uid;
}

Entity *Entity::clone()
{
    Entity *entity = new Entity();
    entity->pos = this->pos;
    entity->size = this->size;
    entity->sprite = this->sprite;
    for (auto &component : _m_components) {
        entity->_m_components[component.first] = std::shared_ptr<AComponent>(component.second->createNew());
    }
    return entity;
}

void Entity::addComponent(std::map<const char *, std::unique_ptr<AComponent>>::iterator it)
{
    std::cout << "add component to entity : " << it->first << " : " << this->id << std::endl;
    this->_m_components[it->first] = std::shared_ptr<AComponent>(it->second->createNew());
}


void Entity::setTexture(sf::Texture texture)
{
    //std::cout << "setting texture" << std::endl;
    this->texture = texture;
    this->sprite.setTexture(this->texture);
}

void Entity::addComponent(const char *type, AComponent *component)
{
    this->_m_components[type] = std::unique_ptr<AComponent>(component);
}


} // namespace sfge
