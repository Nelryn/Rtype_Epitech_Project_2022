#pragma once

#include "AState.hpp"

#include "Map.hpp"
#include "EntityManager.hpp"

namespace sfge
{
    class IState;
    class AState;
    /**
     * @brief  Interface IStateManager
     * @note   Is implemented by a State Manager
     * @retval None
     */
    class IStateManager
    {
        public:
            virtual ~IStateManager() = default;

            /**
             * @brief  Change the current state by pushing a new State in the stack
             * @param  &state: New State
             * @retval None
             */
            virtual void changeState(AState &state) = 0;

            /**
             * @brief  Remove/delete a state from the stack
             * @retval None
             */
            virtual void removeState() = 0;

            /**
             * @brief  Get the current state
             * @note   Get the current state on top of the stack
             * @retval The current State
             */
            virtual IState &getState() = 0;

            virtual void AddEntity(Entity *entity) = 0;

            virtual void setMap(Map *map) = 0;

            /**
             * @brief  Clear all the states in the Stack
             * @note   Emptying the stack
             * @retval None
             */
            virtual void clear() = 0;
    };
}
