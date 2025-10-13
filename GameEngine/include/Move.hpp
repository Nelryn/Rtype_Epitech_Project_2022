
#pragma once

#include "AComponent.hpp"

namespace sfge
{
    class Move : public AComponent
    {
        public:
            Move();
            ~Move();
            void update(Entity *ent) override;
            AComponent *createNew() override;
        protected:
        private:
    };
}