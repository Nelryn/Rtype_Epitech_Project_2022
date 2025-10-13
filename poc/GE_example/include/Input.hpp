/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** Input
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Bitmask.hpp"

class Input {
    public:
        enum class Key {
            None = 0,
            Left = 1,
            Right = 2,
            Up = 3,
            Down = 4,
            Esc = 5
        };
        Input();
        ~Input();
        void Update();
        bool IsKeyPressed(Key keycode); // Returns true if the key is pressed.
        bool IsKeyDown(Key keycode); // Returns true if the key was just pressed.
        bool IsKeyUp(Key keycode); // Returns true if the key was just released.
    protected:
    private:
        Bitmask _thisFrameKeys;
        Bitmask _lastFrameKeys;
};