#pragma once

#include <memory>


namespace sfge
{
    class Entity;

    class AComponent
    {
    public:
        AComponent() = default;
        virtual ~AComponent() = default;
        virtual void update(Entity *ent) = 0;
        virtual AComponent *createNew() = 0;

    protected:
    private:
    };

}