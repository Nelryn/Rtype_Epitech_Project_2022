

#pragma once

#include "AComponent.hpp"

namespace sfge {

class Movable : public AComponent
{
    public:
        Movable();
        ~Movable();
        void update(Entity *entity) override;
        AComponent *createNew() override;
    protected:
    private:
};
} //namespace sfge