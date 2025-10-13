/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** Tile
*/

#pragma once

#include "ResourceAllocator.hpp"

// Stores common tile data.
struct TileInfo
{
    TileInfo() : tileID(-1)
    {
    }
    TileInfo(int textureID, unsigned int tileID, sf::IntRect textureRect) 
    : textureID(textureID), tileID(tileID), textureRect(textureRect) { }
    int tileID;
    int textureID;
    sf::IntRect textureRect;
};