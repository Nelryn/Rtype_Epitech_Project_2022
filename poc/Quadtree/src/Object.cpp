/*
** EPITECH PROJECT, 2022
** MyQuadtree
** File description:
** Object
*/

#include "../include/Quadtree.hpp"

Object::Object(int id, float x, float y, float width, float height) : _id(id), _x(x), _y(y), _width(width), _height(height)
{
    shape.setPosition( _x, _y );
	shape.setSize( sf::Vector2f( _width, _height ) );
	shape.setFillColor( sf::Color( 32, 128, 255 ) );
}

Object::~Object()
{
}

void Object::Draw( sf::RenderTarget &canvas ) {
	canvas.draw( shape );
}