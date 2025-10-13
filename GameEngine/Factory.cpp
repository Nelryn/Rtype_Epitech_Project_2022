#include "Factory.hpp"
#include "SFML/Graphics.hpp"
#include "include/Error/FactoryError.hpp"

namespace sfge {

Factory::Factory()
{
}

Factory::~Factory()
{
    this->m_entityMap.clear();
    this->m_componentMap.clear();
}

void Factory::addComponent(AComponent *component, std::string name)
{
    //std::cout << "Add component: " << name << std::endl;
    //indicator i
    //m_componentMap[name] = component;
}

void Factory::createBuilder(std::string name)
{
    // m_entityMap[name] = std::make_unique<Entity>();
    this->ent = new Entity;
    this->name = name;
}

Entity *Factory::createEntity(std::string name)
{
    Entity *entity = m_entityMap[name]->clone();

    return entity;
}

void Factory::addBuilderComponent(std::vector<std::string> const &components)
{
    try {
        for (auto &comp : components) {
            for (auto &it : this->m_corres) {
                if (it.name == comp) {
                    this->ent->addComponent(it.type.c_str(), m_componentMap[it.name]->createNew());
                }
            }
        }
    } catch (const std::out_of_range& oor) {
        std::cerr << "Component not found " << oor.what() << '\n';
    }
}

void Factory::setBuilderPosition(int x, int y)
{
    this->ent->pos.x = x;
    this->ent->pos.y = y;
}

void Factory::setBuilderSize(int width, int height)
{
    sf::IntRect rect = {0, 0, width, height};

    this->ent->size.x = width;
    this->ent->size.y = height;
    this->ent->sprite.setTextureRect(rect);
}

void Factory::setBuilderSprite(sf::Texture &texture, std::string path)
{
    this->ent->sprite.setTexture(texture);
}

// void Factory::setBuilderIsPlayable(int testx, int testy)
// {
//     this->ent->test.x = testx;
//     this->ent->test.y = testy,
//     std::cout << "Bool factory = " << this->ent->test.x << std::endl;
// }

void Factory::pushBuilder()
{
    this->m_entityMap[this->name] = std::unique_ptr<Entity>(this->ent);
}

} // namespace sfge
