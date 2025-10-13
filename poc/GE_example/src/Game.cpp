/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** Game
*/

#include "../include/Game.hpp"

Game::Game() : _window("TGG")
{
    // Pass in the texture allocator to our splash screen.
    std::shared_ptr<SceneSplashScreen> splashScreen =
    std::make_shared<SceneSplashScreen>(_workingDir, _sceneStateMachine, 
    _window, _textureAllocator); 
    // We now pass the textureAllocator to our game scene.
    std::shared_ptr<SceneGame> gameScene = 
    std::make_shared<SceneGame>(_workingDir, _textureAllocator); 
    unsigned int splashScreenID = _sceneStateMachine.Add(splashScreen); //2
    unsigned int gameSceneID = _sceneStateMachine.Add(gameScene);
    splashScreen->SetSwitchToScene(gameSceneID); //3
    _sceneStateMachine.SwitchTo(splashScreenID); //4
    _deltaTime = _clock.restart().asSeconds();
}

Game::~Game()
{
}

// void Game::ProcessInput()
// {
//     _sceneStateMachine.ProcessInput();
// }

void Game::Update()
{
    _window.Update();
    _sceneStateMachine.Update(_deltaTime);
}

void Game::LateUpdate()
{
    _sceneStateMachine.LateUpdate(_deltaTime);
}

void Game::Draw()
{
    _window.BeginDraw();
    _sceneStateMachine.Draw(_window);
    _window.EndDraw();
}

bool Game::IsRunning() const
{
    // We’ll return true here for now but this will be 
    // changed shortly as we need a method of closing the window.
    return _window.IsOpen();
}

void Game::CalculateDeltaTime()
{
    _deltaTime = _clock.restart().asSeconds();
}

void Game::CaptureInput()
{
    _sceneStateMachine.ProcessInput();
}