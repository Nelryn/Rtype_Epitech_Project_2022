#pragma once

#include "AState.hpp"
#include "Core.hpp"

namespace sfge
{
    class Playstate : public AState
    {
        public:
            Playstate();
            ~Playstate() = default;

            void draw(sf::RenderWindow &window) override final;
            void update() override final;

        private:
    };
}