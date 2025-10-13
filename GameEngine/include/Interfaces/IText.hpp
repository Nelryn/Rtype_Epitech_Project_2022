#pragma once

namespace sfge
{
    class IText
    {
        public:
            virtual ~IText() = default;
            virtual void draw() = 0;
    };
} // namespace sfge
