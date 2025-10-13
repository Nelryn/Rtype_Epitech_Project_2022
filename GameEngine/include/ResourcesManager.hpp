/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** ResourcesManager
*/

#pragma once

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <any>
#include <memory>
#include "iostream"
#include "./Error/RessourcesError.hpp"

namespace sfge {
    class ResourcesManager {
        public:
            ResourcesManager() = default;
            ~ResourcesManager() = default;
            template<typename T>
            void load(std::string name, std::string fileName){
                std::shared_ptr<T> resources(new T);
                try {
                    if (resources->loadFromFile(fileName) == false) {
                        std::string err = "Resources Manager: Load from file error: " + fileName;
                        throw ResourcesError(err);
                    }
                    map[name] = resources;
                } catch (ResourcesError error) {
                    std::cerr << error.what() << std::endl;
                }
            }

            template<typename T>
            T &get(std::string name){
                try {
                    if (map.find(name) == map.end())
                        throw(std::runtime_error("not found"));
                } catch (ResourcesError error) {
                    std::cerr << error.what() << std::endl;
                }
                return *std::any_cast<std::shared_ptr<T>>(map[name]);
            }

            void loadTexture(std::string name, std::string fileName)
            {
                load<sf::Texture>(name, fileName);
            }

            void loadFont(std::string name, std::string fileName)
            {
                return load<sf::Font>(name, fileName);
            }

            sf::Texture &getTexture(std::string name)
            {
                return get<sf::Texture>(name);
            }

            sf::Font &getFont(std::string name)
            {
                return get<sf::Font>(name);
            }

            std::unordered_map<std::string, std::any> map;
    };

}

