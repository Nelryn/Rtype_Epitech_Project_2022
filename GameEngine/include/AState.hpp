#pragma once

#include "IState.hpp"
#include <iostream>
#include "EntityManager.hpp"
#include <iostream>

namespace sfge
{
    /**
     * @brief  Abstract class for States
     * @note   Implement the IState interface
     * @retval None
     */
    class AState : public IState
    {
        public:
            Map *_map;
            /**
             * @brief  Abstract class for States
             * @retval None
             */
            virtual ~AState() = default;

            /**
             * @brief  Draw a state
             * @note
             * @retval None
             */
            void draw(sf::RenderWindow &window) override
            {
                //std::cout << "Draw" << std::endl;
                if (this->_map != nullptr) {
                    //std::cout << "je suis pas null" << std::endl;
                }
                this->_map->draw(window);
                //std::cout << "crash" << std::endl;
                for (auto &it: EntityManager::getInstance()->getEntities()) {
                    it->draw(window);
                }
            }

            /**
             * @brief Set the Map object
             * 
             * @param map 
             */
            void setMap(Map *map) override
            {
                this->_map = map;
                this->_map->addEntityToEntityManager();
            }

            /**
             * @brief  update a state
             * @note
             * @retval None
             */
            void update() override
            {
                this->_map->update();
                for (auto &it : EntityManager::getInstance()->getEntities()) {
                    it->update();
                }
            }
    };
}