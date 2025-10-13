/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** Map
*/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "Entity.hpp"


namespace sfge {
    class Core;
    class Map {
        public:
            Map(std::string file, std::string sprite, sf::Vector2f speed, sf::Vector2f scale);
            ~Map();
            void loadMap(std::string const &filePath, Core *instance);
            void draw(sf::RenderWindow &window);
            void addEntityToEntityManager();
            void setSprite(std::string const &path, Core *instance);
            void update();
            sf::Sprite *spr;
        protected:
        private:
            std::vector<Entity *> m_map;
            std::string m_file;
            std::string m_sprite;
            sf::Vector2f m_speed;
            sf::Vector2f m_scale;
    };
}

