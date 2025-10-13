/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** SceneGame
*/

#pragma once

#include "Object.hpp"
#include "C_Sprite.hpp"
#include "Scene.hpp"
#include "Input.hpp"
#include "WorkingDirectory.hpp"
#include <memory>
#include "C_KeyboardMovement.hpp"
#include "ObjectCollection.hpp"

class SceneGame : public Scene {
    public:
        SceneGame(WorkingDirectory& workingDir,
        ResourceAllocator<sf::Texture>& textureAllocator);
        ~SceneGame();
        void OnCreate() override;
        void OnDestroy() override;
        void ProcessInput() override;
        void Update(float deltaTime) override;
        void Draw(Window& window) override;
        void LateUpdate(float deltaTime) override;
    protected:
    private:
        WorkingDirectory& _workingDir;
        Input _input;
        ResourceAllocator<sf::Texture>& _textureAllocator; 
        ObjectCollection objects;
};
