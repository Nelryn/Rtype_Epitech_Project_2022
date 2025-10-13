/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** Shoot
*/

#include "Shoot.hpp"
#include <iostream>

namespace sfge {
    Shoot::Shoot()
    {
    }

    Shoot::~Shoot()
    {
    }

    void Shoot::update(Entity *ent)
    {
        //std::cout << "Shoot" << std::endl;
    }

    AComponent *Shoot::createNew()
    {
        return new Shoot();
    }
}
