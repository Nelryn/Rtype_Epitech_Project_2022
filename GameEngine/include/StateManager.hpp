#pragma once

#include "IStateManager.hpp"
#include <stack>
#include <iostream>
#include <memory>
#include "EntityManager.hpp"

namespace sfge
{
    /**
     * @brief  Singleton used as a State Manager
     * @note   Manager the states by using a stack
     * @retval None
     */
    class StateManager : public IStateManager
    {
        public:
            /**
             * @brief  Change the current state
             * @note   Push the new state in the stack
             * @param  &newState: The New State
             * @retval None
             */
            void changeState(AState &newState) override;

            /**
             * @brief  Remove/Delete the current state
             * @note   Pop the current state from the stack
             * @retval None
             */
            void removeState() override;

            /**
             * @brief  Get the current state
             * @note   Get the State on top of the stack
             * @retval The current State (IState)
             */
            IState &getState() override;


            /**
             * @brief  Clear all the states
             * @note   Empty the stack
             * @retval None
             */
            void clear() override;

            void AddEntity(Entity *entity) override;

            void setMap(Map *map) override;
            std::stack<std::shared_ptr<AState>> _stateStack;
        private:

        public:
            ~StateManager() = default;
            StateManager(StateManager &other) = delete;
            static StateManager *getInstance();
            EntityManager *entityManager;


        private:
            static StateManager *_stateInstance;
            StateManager();
    };
}
