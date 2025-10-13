#include "StateManager.hpp"
#include "AState.hpp"

namespace sfge
{
    StateManager *StateManager::_stateInstance = nullptr;

    StateManager *StateManager::getInstance()
    {
        if (_stateInstance == nullptr)
            _stateInstance = new StateManager();
        return _stateInstance;
    }

    void StateManager::changeState(AState &newState)
    {
        // //std::cout << "CHANGE STATE" << std::endl;

        _stateStack.push(std::make_shared<AState>(newState));
        // //std::cout << "State pushed in stack" << std::endl;
    }

    void StateManager::removeState()
    {
        ////std::cout"REMOVE STATE" << std::endl;

        _stateStack.pop();
        ////std::cout"State removed from stack" << std::endl;

    }

    IState &StateManager::getState()
    {
        ////std::cout"GET STATE" << std::endl;
        return *_stateStack.top();
    }

    void StateManager::clear()
    {
        // //std::cout << "CLEAR STATE STACK" << std::endl;
        while (!_stateStack.empty())
            _stateStack.pop();

        // //std::cout << "Stack has been emptied" << std::endl;
    }

    StateManager::StateManager()
    {
        this->entityManager = EntityManager::getInstance();
    }

    void StateManager::AddEntity(Entity *entity)
    {
        this->entityManager->addEntity(entity);
    }

    void StateManager::setMap(Map *map)
    {
        this->_stateStack.top()->setMap(map);
    }
}