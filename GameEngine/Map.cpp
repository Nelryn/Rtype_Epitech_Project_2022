/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** Map
*/

#include "include/Map.hpp"
#include "include/pugixml.hpp"
#include "Core.hpp"
#include "MapError.hpp"
#include "StateManager.hpp"


namespace sfge {
    Map::Map(std::string file, std::string sprite, sf::Vector2f speed, sf::Vector2f scale) : m_file(file), m_sprite(sprite),  m_speed(speed), m_scale(scale)
    {
        this->spr = new sf::Sprite();
        this->spr->move(m_speed);
        this->spr->setScale(m_scale);
    }

    Map::~Map()
    {
        delete this->spr;
    }

    void Map::loadMap(std::string const &map, Core *instance)
    {
        pugi::xml_document doc;
        if (!doc.load_file(map.c_str())) {
            std::cout << "error loading map: " << map << std::endl;
            return;
        }
        pugi::xml_node tools = doc.child("map").child("objectgroup");
        //std::cout << "map loaded" << std::endl;
        for (auto &it: tools) {
            Entity *entity = instance->factory->createEntity("Wall");
            try {
                entity->pos.x = it.attribute("x").as_float();
                entity->pos.y = it.attribute("y").as_float();
                entity->size.x = it.attribute("width").as_float();
                entity->size.y = it.attribute("height").as_float();
            } catch (std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
                exit(84);
            }
            this->m_map.push_back(entity);
        }

    }

    void Map::setSprite(std::string const &path, Core *instance)
    {
        //std::cout << "setSprite" << std::endl;
        try {
            this->spr->setTexture(instance->m_resource_manager->getTexture(path));
        } catch (std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        }
    }

    void Map::draw(sf::RenderWindow &window)
    {
        window.draw(*this->spr);
    }

    void Map::addEntityToEntityManager()
    {
        for (auto &it: this->m_map) {
            it->pos.x *= this->m_scale.x * 0.565;
            it->pos.y *= this->m_scale.y * 0.565;
            it->size.x *= this->m_scale.x * 0.565;
            it->size.y *= this->m_scale.y * 0.565;
            Core::getInstance()->m_state->AddEntity(it);
        }
    }

    void Map::update()
    {
        this->spr->move({m_speed.x * -1, 0});
        for (auto &it: this->m_map) {
            it->pos.x += m_speed.x * -1;
        }
    }
}