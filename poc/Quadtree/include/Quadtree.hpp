/*
** EPITECH PROJECT, 2022
** MyQuadtree
** File description:
** Quadtree
*/

#pragma once

#include "Object.hpp"
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <memory>

namespace sfge {
	class Quadtree {
		public:
		/**
			* @brief  Define the dimensions of the first tree (will be used for it's childs)
			* @param  x: Coordinates x of the actual tree
			* @param  y: Coordinates y of the actual tree
			* @param  width: Width of the actual tree
			* @param  height: Height of the actual tree
			* @param  level: Depth of the actual tree
			* @param  maxLevel: Max depth for all trees
			* @retval None
			*/
			Quadtree(float x, float y, float width, float height, int level, int maxLevel);

			/**
			* @brief  Delete the childs
			* @retval None
			*/
			~Quadtree();

			/**
			* @brief  Add 1 object/entity to the Quadtree (the last level)
			* @param  object: The class object (contains positions, width, height)
			* @retval Void
			*/
			void AddObject(std::vector<std::shared_ptr<Object>> objects);
			/**
			* @brief  Delete all objects, used to udpdate objects and chech collisions
			* @retval Void
			*/
			void clearQuadtree();
			/**
			* @brief  Check if the actual tree has object
			* @retval bool
			*/
			bool contains(Quadtree *child, std::shared_ptr<Object> object);
			/**
			* @brief  Draw rectangles representing trees
			* @note   Temporary function
			* @param  &canvas: 
			* @retval Void
			*/
			void Draw(sf::RenderTarget &canvas);
			/**
			* @brief  Inform on a collision by printing object's id
			* @retval Void
			*/
			void detectCollision();
		protected:
		private:
			/**
			* @brief  Position on x axe
			*/
			float _x;

			/**
			* @brief  Position on y axe
			*/
			float _y;

			/**
			* @brief  Width of actual Tree
			*/
			float _width;

			/**
			* @brief  Height of actual tree
			*/
			float _height;

			/**
			* @brief  Level of actual tree
			*/
			int	_level;

			/**
			* @brief  Maximum level of tree (can be compared to maximum number of rectangles)
			*/
			int	_maxLevel;

			/**
			* @brief  Vector of objects
			*/
			std::vector<std::shared_ptr<Object>> _objects;

		/**
			* @brief  Child of the actual quadtree located on the up-left of it's properties
			*/
			Quadtree *_NW;

			/**
			* @brief  Child of the actual quadtree located on the up-right of it's properties
			*/
			Quadtree *_NE;

			/**
			* @brief  Child of the actual quadtree located on the bottom-left of it's properties
			*/
			Quadtree *_SW;

			/**
			* @brief  Child of the actual quadtree located on the bottom-right of it's properties
			*/
			Quadtree *_SE;
			/**
			* @brief  Temporary variable
			*/
			sf::RectangleShape _shape;

	};
}