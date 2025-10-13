#pragma once

#include "Move.hpp"

namespace sfge
{
    class Collidable : public AComponent
    {
        public:
            Collidable();
            ~Collidable();
            void update(Entity *entity) override;
            AComponent *createNew() override;
            void setCollide(bool collide);
            bool getCollide();
        protected:
        private:
            bool collide;
    };
}