/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** Missile
*/

#ifndef MISSILE_HPP_
#define MISSILE_HPP_

#include <vector>
#include <iostream>
#include "Entity.hpp"

namespace sfge {

class Missile : public Entity {
    public:
        /**
         * @brief  
         * @note   constructor
         * @param  color: missile color - sf::Color
         * @param  radius: missile radius - float
         * @retval 
         */
        Missile(sf::Color color, float radius);
        /**
         * @brief  
         * @note   destructor
         * @retval 
         */
        Missile(std::string pathSprite, int nbMissile);
        ~Missile();

        /**
         * @brief  
         * @note   initialization of missile
         * @param  color: missile color - sf::Color
         * @param  radius: missile radius - float
         * @retval sf::CircleShape
         */
        sf::CircleShape createMissile(sf::Color color, float radius);
        /**
         * @brief 
         * @note   update position missile
         * @param  &win: window - sf::RenderWindow
         * @param  moveX: move offset of missile - float
         * @retval None
         */
        void updateMissile(sf::RenderWindow &win, float moveX);
        /**
         * @brief  
         * @note   draw all missile
         * @param  &win: window - sf::RenderWindow
         * @retval None
         */
        void drawMissile(sf::RenderWindow &win);
        /**
         * @brief  
         * @note   add missile
         * @param  pos: missile's position - sf::Vector2f
         * @retval None
         */
        void addMissile(sf::Vector2f pos);
        /**
         * @brief  
         * @note   get all missile
         * @retval std::vector<sf::CircleShape>
         */
        std::vector<sf::CircleShape> getListMissile() const;
        void createMissileSprite(std::string &path);

    protected:
    private:
        /**
         * @brief  
         * @note   list missile
         * @retval None
         */
        std::vector<sf::CircleShape> _bullets;
        /**
         * @brief  
         * @note   model missile
         * @retval None
         */
        sf::CircleShape _bullet;
        int _nbMissile;
        std::vector<sf::Sprite> _missiles;
};
}

#endif /* !MISSILE_HPP_ */
