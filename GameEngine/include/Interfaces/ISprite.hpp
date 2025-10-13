#pragma once

namespace sfge
{
    class ISprite
    {
        public:
            virtual ~ISprite() = default;
            virtual void draw() = 0;
    };
} // namespace sfge

