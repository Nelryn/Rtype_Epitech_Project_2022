#include "EntityManager.hpp"
#include <iostream>

namespace sfge {
    EntityManager *EntityManager::_instance = nullptr;

    EntityManager *EntityManager::getInstance() {
        if (_instance == nullptr)
            _instance = new EntityManager();
        return _instance;
    }

    EntityManager::EntityManager() {
    }

    EntityManager::~EntityManager() {
        clear();
    }

    void EntityManager::addEntity(Entity *entity) {
        entity->setId(this->m_entities.size() + 1);
        this->m_entities.push_back(std::shared_ptr<Entity>(entity));
    }

    Entity *EntityManager::getEntity(unsigned int id) {
        for (auto &it: this->m_entities) {
            if (it->getId() == id) {
                return it.get();
            }
        }
        return nullptr;
    }

    void EntityManager::clear() {
        this->m_entities.clear();
    }

    std::vector<std::shared_ptr<Entity>> EntityManager::getEntities() {
        return this->m_entities;
    }

} // namespace sfge