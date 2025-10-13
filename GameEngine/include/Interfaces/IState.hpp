#pragma once
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "Core.hpp"

namespace sfge
{
    /**
     * @brief  Interface IState
     * @note   Any Ne state will have to implement this interface
     * @retval None
     */
    class IState
    {
        public:
            virtual ~IState() = default;
            /**
             * @brief  Draw a state
             * @note
             * @retval None
             */
            virtual void draw(sf::RenderWindow &window) = 0;

            /**
             * @brief Set the Map object
             * 
             * @param map 
             */

            virtual void setMap(Map *map) = 0;

            /**
             * @brief  Update a state
             * @note
             * @retval None
             */
            virtual void update() = 0;
    };
}
