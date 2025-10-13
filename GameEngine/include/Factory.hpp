


#pragma once

#include <iostream>
#include <string>
#include "Entity.hpp"
#include <vector>
#include "AComponent.hpp"
#include "Error/FactoryError.hpp"

namespace sfge
{

    class indicator {
        public:
            indicator() = default;
            ~indicator() = default;
            std::string name;
            std::string type;
    };
    class Factory
    {
        public:
            Factory();
            ~Factory();
            void addComponent(AComponent *component, std::string name);
            void createBuilder(std::string name);
            template <typename T>
            void addComponent(std::string const &name) {
                indicator ind;
                ind.name = name;
                ind.type = typeid(T).name();
                this->m_corres.push_back(ind);
                m_componentMap[name] = std::unique_ptr<AComponent>(new T);
                std::cout << "create" << std::endl;
                for (auto &it : this->m_componentMap) {
                    it.second->update(nullptr);
                }
                std::cout << "fin" << std::endl;
            }
            Entity *createEntity(std::string name);
            void setBuilderPosition(int x, int y);
            void setBuilderSize(int width, int height);
            void setBuilderSprite(sf::Texture &text, std::string path);
            void pushBuilder();

            void addBuilderComponent(std::vector<std::string> const &components);

        private:
            std::map<std::string, std::unique_ptr<Entity>> m_entityMap;
            std::vector<indicator> m_corres;
            std::map<std::string, std::unique_ptr<AComponent>> m_componentMap;
            Entity* ent;
            std::string name;
    };
}
