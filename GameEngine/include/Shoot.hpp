/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** Shoot
*/

#ifndef SHOOT_HPP_
#define SHOOT_HPP_

#include "AComponent.hpp"

namespace sfge {
    class Shoot : public sfge::AComponent 
    {
        public:
            Shoot();
            ~Shoot();
            void update(Entity *ent) override;
            AComponent *createNew() override;
    
        protected:
        private:
    };
}

#endif /* !SHOOT_HPP_ */
