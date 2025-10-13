/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** Component
*/

#pragma once

#include "Window.hpp"

class Object;

class Component {
    public:
        Component(Object* owner) : owner(owner){}
        virtual void Awake() {};
        virtual void Start() {};
        virtual void Update(float deltaTime) {};
        virtual void LateUpdate(float deltaTime) {};
        virtual void Draw(Window& window) {};
    protected:
        Object* owner;
    private:
};