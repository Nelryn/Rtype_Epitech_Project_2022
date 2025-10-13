/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** SceneSplashScreen
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "SceneStateMachine.hpp"
#include "WorkingDirectory.hpp"
#include "ResourceAllocator.hpp"

class SceneSplashScreen : public Scene {
    public:
        SceneSplashScreen(WorkingDirectory& workingDir, 
        SceneStateMachine& sceneStateMachine, Window& window,
        ResourceAllocator<sf::Texture>& textureAllocator);
        ~SceneSplashScreen();
        void OnCreate() override;
        void OnDestroy() override;
        void OnActivate() override;
        void SetSwitchToScene(unsigned int id);
        void Update(float deltaTime) override;
        void Draw(Window& window) override;
    protected:
    private:
        sf::Texture _splashTexture;
        sf::Sprite _splashSprite;
        WorkingDirectory& _workingDir;
        SceneStateMachine& _sceneStateMachine;
        Window& _window;
        // We want to show this scene for a set amount of time
        float _showForSeconds;
        // How long the scene has currently been visible.
        float _currentSeconds;
        // The state we want to transition to when this scenes time expires.
        unsigned int _switchToState;
        ResourceAllocator<sf::Texture>& _textureAllocator;
};