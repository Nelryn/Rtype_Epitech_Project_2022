/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** Input
*/

#include "../include/Input.hpp"

Input::Input()
{
}

Input::~Input()
{
}

void Input::Update()
{
    _lastFrameKeys.SetMask(_thisFrameKeys); // 1
    _thisFrameKeys.SetBit((int)Key::Left,
    (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || 
    (sf::Keyboard::isKeyPressed(sf::Keyboard::A))); // 2
    _thisFrameKeys.SetBit((int)Key::Right,
    (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || 
    (sf::Keyboard::isKeyPressed(sf::Keyboard::D)));
    _thisFrameKeys.SetBit((int)Key::Up,
    (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || 
    (sf::Keyboard::isKeyPressed(sf::Keyboard::W)));
    _thisFrameKeys.SetBit((int)Key::Down,
    (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || 
    (sf::Keyboard::isKeyPressed(sf::Keyboard::S)));
    _thisFrameKeys.SetBit((int)Key::Esc), 
    sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
}

// Return true if the specified key is currently being pressed.
bool Input::IsKeyPressed(Key keycode) 
{
    return _thisFrameKeys.GetBit((int)keycode);
}

// Returns true if the key was just pressed 
// (i.e. registered as pressed this frame but not the previous).
bool Input::IsKeyDown(Key keycode)
{
    bool lastFrame = _lastFrameKeys.GetBit((int)keycode);
    bool thisFrame = _thisFrameKeys.GetBit((int)keycode);
    return thisFrame && !lastFrame;
}

// Returns true if the key was just released (i.e. registered as 
// pressed last frame but not the current frame).
bool Input::IsKeyUp(Key keycode)
{
    bool lastFrame = _lastFrameKeys.GetBit((int)keycode);
    bool thisFrame = _thisFrameKeys.GetBit((int)keycode);
    return !thisFrame && lastFrame;
}