/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** SceneSplashScreen
*/

#include "../include/SceneSplashScreen.hpp"

SceneSplashScreen::SceneSplashScreen(WorkingDirectory& workingDir, SceneStateMachine& sceneStateMachine, Window& window, ResourceAllocator<sf::Texture>& textureAllocator) : _sceneStateMachine(sceneStateMachine), _workingDir(workingDir), _window(window), _switchToState(0), _currentSeconds(0.f), _showForSeconds(3.f), _textureAllocator(textureAllocator)
{
}

SceneSplashScreen::~SceneSplashScreen()
{
}

void SceneSplashScreen::OnCreate()
{
    int textureID = _textureAllocator.Add(_workingDir.Get() + "animegirlredsword.jpg"); //1
    if(textureID >= 0) {
        std::shared_ptr<sf::Texture> texture = _textureAllocator.Get(textureID);
        _splashSprite.setTexture(*texture);
        sf::FloatRect spriteSize = _splashSprite.getLocalBounds();
        _splashSprite.setOrigin(spriteSize.width * 0.5f,
        spriteSize.height * 0.5f);
        _splashSprite.setScale(0.5f, 0.5f);
        sf::Vector2u windowCentre = _window.GetCentre();
        _splashSprite.setPosition(windowCentre.x, windowCentre.y);
    }
}

void SceneSplashScreen::OnActivate()
{
    // Resets the currentSeconds count whenever the scene is activated.
    _currentSeconds = 0.f;
}

void SceneSplashScreen::OnDestroy()
{
}

void SceneSplashScreen::SetSwitchToScene(unsigned int id)
{
    // Stores the id of the scene that we will transition to.
    _switchToState = id;
}

void SceneSplashScreen::Update(float deltaTime)
{
    _currentSeconds += deltaTime;
    if(_currentSeconds >= _showForSeconds) {
        // Switches states.
        _sceneStateMachine.SwitchTo(_switchToState);
    }
}
void SceneSplashScreen::Draw(Window& window)
{
    window.Draw(_splashSprite);
}