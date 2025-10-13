/*
** EPITECH PROJECT, 2022
** MyQuadtree
** File description:
** Object
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Object {
    public:
        Object(int id, float x, float y, float width, float height);
        ~Object();
		float _x;
		float _y;
		float _width;
		float _height;
		int _id;
	    void Draw(sf::RenderTarget &canvas);
    protected:
    private:
		sf::RectangleShape		shape;

};
