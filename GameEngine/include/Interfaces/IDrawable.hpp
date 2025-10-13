
#pragma once

namespace sfge
{
    class IDrawable
    {
        public:
            virtual ~IDrawable() = default;
            virtual void draw() = 0;
    };
} // namespace sfge