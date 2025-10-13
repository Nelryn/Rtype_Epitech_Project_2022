/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** C_KeyboardMovement
*/

#pragma once

#include "Input.hpp"
#include "C_Animation.hpp"
#include <memory>

class C_KeyboardMovement : public Component {
    public:
        C_KeyboardMovement(Object * owner);
        ~C_KeyboardMovement();
        void SetInput(Input* input);
        void SetMovementSpeed(int moveSpeed);
        void Update(float deltaTime) override;
        void Awake() override;
    protected:
    private:
        int moveSpeed;
        Input* input;
        // We need to store a reference to the 
        // animation component for now.
        std::shared_ptr<C_Animation> animation; 
};
