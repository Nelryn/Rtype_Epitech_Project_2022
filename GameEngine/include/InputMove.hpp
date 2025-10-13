#ifndef INPUTMOVE_HPP_
#define INPUTMOVE_HPP_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace sfge {

class InputMove {
    public:
        /**
         * @brief  
         * @note   
         * @param  up: key for move up - sf::Keyboard::Key
         * @param  down: key for move down - sf::Keyboard::Key
         * @param  right: key for move right - sf::Keyboard::Key
         * @param  left: key for move left - sf::Keyboard::Key
         * @retval 
         */
        InputMove(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key right, sf::Keyboard::Key left);
        /**
         * @brief  
         * @note   constructor
         * @retval 
         */
        InputMove();
        /**
         * @brief  
         * @note   destructor
         * @retval 
         */
        ~InputMove();

        /**
         * @brief  
         * @note   Move a player or an entity
         * @param  &player: entity - sf::Sprite
         * @param  key: event's key when is press - sf::Event::KeyEvent
         * @param  speed: move speed - float
         * @retval None
         */
        void move(sf::Sprite &player, sf::Event::KeyEvent key, float speed);
        /**
         * @brief  
         * @note   set moving key
         * @param  up: key for move up - sf::Keyboard::Key
         * @param  down: key for move down - sf::Keyboard::Key
         * @param  right: key for move right - sf::Keyboard::Key
         * @param  left: key for move left - sf::Keyboard::Key
         * @retval None
         */
        void setKey(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key right, sf::Keyboard::Key left);

    protected:
    private:
        /**
         * @brief  
         * @note   key for move up - sf::Keyboard::Key
         * @retval None
         */
        sf::Keyboard::Key _up;
        /**
         * @brief  
         * @note   key for move down - sf::Keyboard::Key
         * @retval None
         */
        sf::Keyboard::Key _down;
        /**
         * @brief  
         * @note   key for move right - sf::Keyboard::Key
         * @retval None
         */
        sf::Keyboard::Key _right;
        /**
         * @brief  
         * @note   key for move left - sf::Keyboard::Key
         * @retval None
         */
        sf::Keyboard::Key _left;
};

class InputShoot {
    public:
        /**
         * @brief  
         * @note   constructor
         * @param  shoot: key for shoot - sf::Keyboard::Key
         * @retval 
         */
        InputShoot(sf::Keyboard::Key shoot);
        /**
         * @brief  
         * @note   destructor
         * @retval 
         */
        ~InputShoot();

        /**
         * @brief  
         * @note   is move ball
         * @param  key: event's key when is press - sf::Event::KeyEvent
         * @retval bool
         */
        bool isMove(sf::Event::KeyEvent key);
        /**
         * @brief  
         * @note   set shoot key
         * @param  shoot: key for shoot - sf::Keyboard::Key
         * @retval None
         */
        void setKey(sf::Keyboard::Key shoot);

    protected:
    private:
        /**
         * @brief  
         * @note   shoot key - sf::Keyboard::Key
         * @retval None
         */
        sf::Keyboard::Key _shoot;
};

}

#endif /* !INPUTMOVE_HPP_ */
