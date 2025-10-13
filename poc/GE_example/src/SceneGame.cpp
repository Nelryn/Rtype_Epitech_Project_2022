/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** SceneGame
*/

#include "../include/SceneGame.hpp"
#include <iostream>

SceneGame::SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator) : _workingDir(workingDir), _textureAllocator(textureAllocator)
{
    //std::cout << "some begin" << std::endl;
    //std::cout << "some end" << std::endl;
}

SceneGame::~SceneGame()
{
}

void SceneGame::OnCreate()
{
    // We now need to temporarily store a reference to the player as
    // its no longer a class variable.
    std::shared_ptr<Object> player = std::make_shared<Object>();
    // Add the components.
    auto sprite = player->AddComponent<C_Sprite>();
    sprite->SetTextureAllocator(&_textureAllocator);
    auto movement = player->AddComponent<C_KeyboardMovement>();
    movement->SetInput(&_input);
    auto animation = player->AddComponent<C_Animation>(); 
    int vikingTextureID = _textureAllocator.Add(_workingDir.Get() + "Viking.png");
    const int frameWidth = 165; //1
    const int frameHeight = 145;
    // We pass in the animations direction when creating a new animation.
    // The character in the sprites faces right so we set that 
    // as the initial direction.
    std::shared_ptr<Animation> idleAnimation = 
    std::make_shared<Animation>(FacingDirection::Right);
    // How long we want to show each frame.
    const float idleAnimFrameSeconds = 0.2f; 
    idleAnimation->AddFrame(vikingTextureID, 600, 0, 
    frameWidth, frameHeight, idleAnimFrameSeconds);//3
    idleAnimation->AddFrame(vikingTextureID, 800, 0, 
    frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 0, 145, 
    frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 200, 145, 
    frameWidth, frameHeight, idleAnimFrameSeconds);
    // This adds the idle animation that we’ve just built. 
    // It will also set it as our active animation.
    animation->AddAnimation(AnimationState::Idle, idleAnimation); 
    // Don’t forget to add the player to the object collection.
    objects.Add(player);
}

void SceneGame::OnDestroy()
{
}

void SceneGame::ProcessInput()
{
    _input.Update();
}

void SceneGame::Update(float deltaTime)
{
    // Add the below line to process our new objects at the 
    // beginning of each frame.
    objects.ProcessRemovals(); // Processes any object removals.
    objects.ProcessNewObjects();
    objects.Update(deltaTime);
}

void SceneGame::Draw(Window& window)
{
    objects.Draw(window); // This will draw our new sprite component.
}

void SceneGame::LateUpdate(float deltaTime)
{
    objects.LateUpdate(deltaTime);
}