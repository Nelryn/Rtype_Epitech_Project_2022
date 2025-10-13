/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** C_Sprite
*/

#include "../include/C_Sprite.hpp"
#include "../include/Object.hpp"

C_Sprite::C_Sprite(Object* owner) : Component(owner), currentTextureID(-1)
{
}

void C_Sprite::Load(const std::string& filePath)
{
    if (allocator) {
        int textureID = allocator->Add(filePath);
        if(textureID >= 0 && textureID != currentTextureID) {
            currentTextureID = textureID;
            std::shared_ptr<sf::Texture> texture = allocator->Get(textureID);
            _sprite.setTexture(*texture);
        }
    }
}

void C_Sprite::Load(int id)
{
    if (id >= 0 && id != currentTextureID) {
        currentTextureID = id;
        std::shared_ptr<sf::Texture> texture = allocator->Get(id);
        _sprite.setTexture(*texture);
    }
}

void C_Sprite::Draw(Window& window)
{
    window.Draw(_sprite);
}

void C_Sprite::LateUpdate(float deltaTime)
{
    _sprite.setPosition(owner->transform->GetPosition()); // 2
}

void C_Sprite::SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator) 
{
    this->allocator = allocator;
}

void C_Sprite::SetTextureRect(int x, int y, int width, int height)
{
    _sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

void C_Sprite::SetTextureRect(const sf::IntRect& rect)
{
    _sprite.setTextureRect(rect);
}