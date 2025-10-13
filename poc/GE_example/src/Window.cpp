/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** Window
*/

#include "../include/Window.hpp"

Window::Window(const std::string& windowName)
: _window(sf::VideoMode(800, 600), windowName, sf::Style::Titlebar) // 1
{
    _window.setVerticalSyncEnabled(true); // 2
}

Window::~Window()
{

}

void Window::Update()
{
    sf::Event event; // 3
    if (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _window.close();
        }
    }
}

void Window::BeginDraw() // 4
{
    _window.clear(sf::Color::White);
}

void Window::Draw(const sf::Drawable& drawable)
{
    _window.draw(drawable);
}

void Window::EndDraw()
{
    _window.display();
}

sf::Vector2u Window::GetCentre() const
{
    sf::Vector2u size = _window.getSize();

    return sf::Vector2u(size.x / 2, size.y / 2);
}

bool Window::IsOpen() const
{
    return _window.isOpen();
}
