/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** C_KeyboardMovement
*/

#include "../include/C_KeyboardMovement.hpp"
#include "../include/Object.hpp"
#include <iostream>

C_KeyboardMovement::C_KeyboardMovement(Object* owner) : Component(owner), moveSpeed(100)
{
}

C_KeyboardMovement::~C_KeyboardMovement()
{
}

void C_KeyboardMovement::SetInput(Input* input)
{
    this->input = input;
}

void C_KeyboardMovement::SetMovementSpeed(int moveSpeed)
{
    this->moveSpeed = moveSpeed;
}

void C_KeyboardMovement::Update(float deltaTime)
{
    int xMove = 0;
    int yMove = 0;
    float xFrameMove = 0;
    float yFrameMove = 0;

    if (input == nullptr) {
        return;
    }
    if (input->IsKeyPressed(Input::Key::Left)) {
        xMove = -moveSpeed;
        animation->SetAnimationDirection(FacingDirection::Left); // New line
    } else if (input->IsKeyPressed(Input::Key::Right)) {
        xMove = moveSpeed;
        animation->SetAnimationDirection(FacingDirection::Right); // New line
    }
    if (input->IsKeyPressed(Input::Key::Up)) {
        yMove = -moveSpeed;
    } else if (input->IsKeyPressed(Input::Key::Down)) {
        yMove = moveSpeed;
    }
    xFrameMove = xMove * deltaTime;
    yFrameMove = yMove * deltaTime;
    owner->transform->AddPosition(xFrameMove, yFrameMove);
}

void C_KeyboardMovement::Awake()
{
    animation = owner->GetComponent<C_Animation>();
}