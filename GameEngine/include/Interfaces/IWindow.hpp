#pragma once 


#include "IDrawable.hpp"
#include "IText.hpp"
#include "ISprite.hpp"
#include <string>
#include <SFML/Graphics.hpp>


namespace sfge {

    class IWindow
    {
        public:
            virtual ~IWindow() = default;
            //virtual void createWindow(int width, int height, const std::string &name) = 0;
            virtual void closeWindow() = 0;
            virtual void displayWindow() = 0;
            virtual void clearWindow() = 0;
            virtual void pollEvent() = 0;
            virtual bool isOpen() const = 0;
            virtual void draw(IDrawable *drawable) = 0;
            virtual void drawText(IText *text) = 0;
            virtual void drawSprite(ISprite *sprite) = 0;
            virtual void createWindow(int width, int height, const std::string &title) = 0;
            virtual void setFramerateLimit(int limit) = 0;
            virtual sf::RenderWindow &getWindow() = 0;

    };

} // namespace sfge
