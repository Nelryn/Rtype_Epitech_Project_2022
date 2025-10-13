#include "Position.hpp"

namespace sfge
{
    Position::Position()
    {
    }

    Position::~Position()
    {
    }

    void Position::update()
    {
    }

    float Position::getX()
    {
        return x;
    }

    float Position::getY()
    {
        return y;
    }

    void Position::setX(float x)
    {
        this->x = x;
    }

    void Position::setY(float y)
    {
        this->y = y;
    }

    
} // namespace sfge
