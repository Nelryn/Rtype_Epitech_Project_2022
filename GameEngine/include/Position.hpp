#pragma once

#include "AComponent.hpp"


namespace sfge
{
    class Position : public AComponent
    {
        public:
            Position();
            ~Position();
            void update();
            void setX(float x);
            void setY(float y);
            float getX();
            float getY();
        protected:
        private:
            float x;
            float y;
    };
    
} // namespace sfge

