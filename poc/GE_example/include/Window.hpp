/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** Window
*/

#pragma once

#include <SFML/Graphics.hpp>

class Window {
    public:
        Window(const std::string& windowName);
        ~Window();
        void Update();
        void BeginDraw();
        void Draw(const sf::Drawable& drawable);
        void EndDraw();
        sf::Vector2u GetCentre() const;
        bool IsOpen() const;
    protected:
    private:
        sf::RenderWindow _window;
};
