#pragma once


#include "Interfaces/IWindow.hpp"

#include <SFML/Graphics.hpp>

namespace sfge
{
    class Window : public IWindow
    {
        public:
            Window(int width, int height, const std::string& title);
            ~Window();
            void createWindow(int width, int height, const std::string &title) override;
            void closeWindow() override;
            void displayWindow() override;
            void clearWindow() override;
            void pollEvent() override;
            bool isOpen() const override;
            void draw(IDrawable *drawable) override;
            void drawText(IText *text) override;
            void drawSprite(ISprite *sprite) override;
            void setFramerateLimit(int limit) override;
            sf::RenderWindow &getWindow();

        private:
            sf::RenderWindow m_window;
    };
}