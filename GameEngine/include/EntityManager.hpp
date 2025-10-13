#pragma once


#include "Entity.hpp"


namespace sfge {
    class EntityManager {
        public:
            ~EntityManager();

            std::vector<std::shared_ptr<Entity>> m_entities;
            /**
             * @brief  Get the instance of the EntityManager
             * @note   Singleton
             * @retval The instance of the EntityManager
             */
            static EntityManager *getInstance();

            static EntityManager *_instance;

            void addEntity(Entity *entity);

            void removeEntity(unsigned int id) {
                std::cout << "remove entity : " << id << std::endl;

                for (int i = 0; i < this->m_entities.size(); i++) {
                    if (this->m_entities.at(i)->getId() == id) {
                        this->m_entities.erase(this->m_entities.begin() + i);
                    }
                }
            }

            Entity *getEntity(unsigned int id);

            std::vector<std::shared_ptr<Entity>> getEntities();

            template<typename T>
            std::vector<std::shared_ptr<Entity>> getEntitiesWithComponent() {
                std::vector<std::shared_ptr<Entity>> entities;
                for (auto &entity : this->m_entities) {
                    if (entity->hasComponent<T>())
                        entities.push_back(entity);
                }
                return entities;
            }

            EntityManager(EntityManager &other) = delete;

            void clear();
        protected:
            EntityManager();
    };

}