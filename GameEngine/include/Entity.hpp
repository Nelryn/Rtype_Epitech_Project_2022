#pragma once

#include "AComponent.hpp"
#include <vector>
#include <unordered_map>
#include <memory>
#include <typeinfo>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstring>
// #include "ClientUdpAsync.hpp"

namespace sfge
{
    class Entity
    {
        public:
            Entity();
            ~Entity();
            void update();
            void draw(sf::RenderWindow &window);
            Entity *clone();

            void addComponent(std::map<const char *, std::unique_ptr<AComponent>>::iterator it);

            void addComponent(const char *type, AComponent *component);
            void setId(unsigned int id);

            unsigned int getId() const;
            void setUid(unsigned char id);
            unsigned char getUid() const;

            void setComponentList(std::map<const char *, std::unique_ptr<AComponent>> componentList);

            template<typename T>
            std::shared_ptr<T> getComponent() {
                for (auto &it: this->_m_components) {
                    if (std::strcmp(it.first, typeid(T).name()) == 0) {
                        return std::dynamic_pointer_cast<T>(it.second);
                    }
                }
                return (nullptr);
            }
            template<typename T>
            void addComponent(T *component) {

                _m_components[typeid(T).name()] = std::unique_ptr<AComponent>(component);
            }
            template<typename T>
            void removeComponent() {
                _m_components.erase(typeid(T).name());
            }
            template<typename T>
            bool hasComponent() {
                for (auto &it: this->_m_components) {
                    if (std::strcmp(it.first, typeid(T).name()) == 0) {
                        return true;
                    }
                }
                return false;
            }

            void setTexture(sf::Texture texture);

            sf::Vector2f pos;
            sf::Vector2f vel;
            sf::Vector2f size;
            sf::Vector2f old;
            sf::Sprite sprite;
            sf::Texture texture;
            std::string name;

        protected:
        private:
            std::unordered_map<const char *, std::shared_ptr<AComponent>> _m_components;
            unsigned int id;
            unsigned char _uid;

    };
}
