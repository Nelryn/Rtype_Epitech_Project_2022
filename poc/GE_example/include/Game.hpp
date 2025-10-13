/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** Game
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "WorkingDirectory.hpp"
#include "Window.hpp"
#include "Input.hpp"
#include "SceneSplashScreen.hpp"
#include "SceneGame.hpp"

class Game {
    public:
        Game();
        ~Game();
        // void ProcessInput();
        void Update();
        void LateUpdate();
        void Draw();
        void CalculateDeltaTime();
        bool IsRunning() const;
        void CaptureInput();
    protected:
    private:
        Window _window;
        WorkingDirectory _workingDir;
        sf::Clock _clock;
        float _deltaTime;
        SceneStateMachine _sceneStateMachine;
        ResourceAllocator<sf::Texture> _textureAllocator;
};