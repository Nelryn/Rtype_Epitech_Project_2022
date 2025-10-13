/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** C_Transform
*/

#pragma once

#include "C_KeyboardMovement.hpp"

class C_Transform : public Component{
    public:
        C_Transform(Object* owner);
        ~C_Transform();
        void SetPosition(float x, float y);
        void SetPosition(const sf::Vector2f &pos);
        void AddPosition(float x, float y);
        void AddPosition(sf::Vector2f pos);
        // Allows us to set x/y values separately.
        void SetX(float x);
        void SetY(float y);
        void AddX(float x);
        void AddY(float y);
        const sf::Vector2f& GetPosition() const;
    protected:
    private:
        sf::Vector2f position;
};
