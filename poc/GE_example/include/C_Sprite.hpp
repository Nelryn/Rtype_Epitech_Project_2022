/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** C_Sprite
*/

#pragma once

#include "C_Transform.hpp"
#include "ResourceAllocator.hpp"

class C_Sprite : public Component {
    public:
        C_Sprite(Object* owner);
        // Loads a sprite from file.
        void Load(const std::string& filePath);
        void Load(int id);
        // We override the draw method so we can draw our sprite.
        void Draw(Window& window) override;
        void LateUpdate(float deltaTime) override; 
        void SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator); // 1
        void SetTextureRect(int x, int y, int width, int height);
        void SetTextureRect(const sf::IntRect& rect);
    protected:
    private:
        ResourceAllocator<sf::Texture>* allocator;
        sf::Sprite _sprite;
        int currentTextureID; // We’ll now keep track of our currently set texture.
};