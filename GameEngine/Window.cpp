
#include "Window.hpp"
#include "Core.hpp"

namespace sfge
{
    Window::Window(int width, int height, const std::string& title)
        : m_window(sf::VideoMode(width, height), title)
    {
    }

    Window::~Window()
    {

    }

    void Window::createWindow(int width, int height, const std::string &title)
    {
        m_window.create(sf::VideoMode(width, height), title);
    }


    void Window::closeWindow()
    {
        m_window.close();
    }

    void Window::displayWindow()
    {
        m_window.display();
    }

    void Window::clearWindow()
    {
        m_window.clear();
    }

    void Window::pollEvent()
    {
        sf::Event event;

        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
            if (sfge::Core::getInstance()->_online)
                sfge::Core::getInstance()->_clientUdp->manageEvent(event);
        }
    }

    bool Window::isOpen() const
    {
        return m_window.isOpen();
    }

    void Window::draw(IDrawable *drawable)
    {
        //m_window.draw(drawable);
    }

    void Window::drawText(IText *text)
    {
        //m_window.draw(text->getText());
    }

    void Window::drawSprite(ISprite *sprite)
    {
        //m_window.draw(sprite->getSprite());
    }

    void Window::setFramerateLimit(int limit)
    {
        m_window.setFramerateLimit(limit);
    }

    sf::RenderWindow &Window::getWindow()
    {
        return m_window;
    }


}

