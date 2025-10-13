/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** ObjectCollection
*/

#pragma once

#include <memory>
#include <vector>
#include "Object.hpp"

class ObjectCollection {
    public:
        ObjectCollection();
        ~ObjectCollection();
        void Add(std::shared_ptr<Object> object);
        void Update(float deltaTime);
        void LateUpdate(float deltaTime);
        void Draw(Window& window);
        void ProcessNewObjects(); // 1
        void ProcessRemovals();
    protected:
    private:
        std::vector<std::shared_ptr<Object>> objects;
        std::vector<std::shared_ptr<Object>> newObjects; // 2
};

