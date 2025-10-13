#pragma once




namespace sfge
{
    class AComponent
    {
        public:
            AComponent() = default;
            virtual ~AComponent() = default;
            virtual void update() = 0;
        protected:
        private:
    };

}