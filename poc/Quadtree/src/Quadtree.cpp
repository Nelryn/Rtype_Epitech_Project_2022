/*
** EPITECH PROJECT, 2022
** MyQuadtree
** File description:
** Quadtree
*/

#include "../include/Quadtree.hpp"

namespace sfge {
	Quadtree::Quadtree(float x, float y, float width, float height, int level, int maxLevel) : _x(x), _y(y), _width(width), _height(height), _level(level), _maxLevel(maxLevel)
	{
		// std::cout << "Quadtree cons begin, maxlevel: " << _maxLevel << std::endl;
		_shape.setPosition(_x, _y);
		_shape.setSize(sf::Vector2f(_width, _height));
		_shape.setFillColor(sf::Color(0, 0, 0, 0));
		_shape.setOutlineThickness(1.0f);
		_shape.setOutlineColor(sf::Color(64, 128, 255));
		if (_level == _maxLevel) {
			return;
		}
		_NW = new Quadtree(_x, _y, _width / 2.0f, _height / 2.0f, _level+1, _maxLevel);
		_NE = new Quadtree(_x + _width / 2.0f, _y, _width / 2.0f, _height / 2.0f, _level+1, _maxLevel);
		_SW = new Quadtree(_x, _y + _height / 2.0f, _width / 2.0f, _height / 2.0f, _level+1, _maxLevel);
		_SE = new Quadtree(_x + _width / 2.0f, _y + _height / 2.0f, _width / 2.0f, _height / 2.0f, _level+1, _maxLevel);
		// std::cout << "Quadtree cons end" << std::endl;

	}

	Quadtree::~Quadtree()
	{
		// std::cout << "Quadtree des begin" << std::endl;
		if (_level == _maxLevel)
			return;

		delete _NW;
		delete _NE;
		delete _SW;
		delete _SE;
		// std::cout << "Quadtree des end" << std::endl;
	}

	void Quadtree::AddObject(std::vector<std::shared_ptr<Entity>> objects)
	{
		// std::cout << "Quadtree add Object begin" << std::endl;
		for (auto object = objects.begin(); object != objects.end(); object++) {
			if (_level == _maxLevel) {
				// std::cout << "-----\nPushed back start: " << (*object)._id << std::endl;
				_objects.push_back((*object));
				std::cout << object.pos.x << std::endl;
				// std::cout << "Pushed back end: " << _objects.size() << std::endl;
			} else {
				if (contains(_NW, (*object))) {
					_NW->AddObject(objects);
					return;
				} else if (contains(_NE, (*object))) {
					_NE->AddObject(objects);
					return;
				} else if (contains(_SW, (*object))) {
					_SW->AddObject(objects);
					return;
				} else if (contains(_SE, (*object))) {
					_SE->AddObject(objects);
					return;
				}
				if (contains(this, (*object))) {
					_objects.push_back((*object));
				}
			}
		}
		// std::cout << "Quadtree add Object end" << std::endl;
	}

	void Quadtree::clearQuadtree()
	{
		// std::cout << "Quadtree clear begin" << std::endl;
		if (_level == _maxLevel) {
			_objects.clear();
			return;
		} else {
			_NW->clearQuadtree();
			_NE->clearQuadtree();
			_SW->clearQuadtree();
			_SE->clearQuadtree();
		}
		if (!_objects.empty()) {
			_objects.clear();
		}
		// std::cout << "Quadtree clear end" << std::endl;
	}

	bool Quadtree::contains(Quadtree *child, std::shared_ptr<Entity> object)
	{
		// std::cout << "Quadtree contains begin" << std::endl;
		if (object->pos.x < child->_x || object->pos.y < child->_y
		|| object->pos.x > child->_x + child->_width  ||
		object->pos.y > child->_y + child->_height ||
		object->pos.x + object->size.x < child->_x ||
		object->pos.y + object->size.y < child->_y ||
		object->pos.x + object->size.x > child->_x + child->_width ||
		object->pos.y + object->size.y > child->_y + child->_height) {
			// std::cout << "Quadtree contains end" << std::endl;
			return false;
		}
		// std::cout << "Quadtree contains end" << std::endl;
		return true;
	}

	void Quadtree::Draw(sf::RenderTarget &canvas)
	{
		// std::cout << "Quadtree draw begin" << std::endl;
		std::stringstream ss;
		ss << _objects.size();
		std::string numObjectsStr = ss.str();
		canvas.draw(_shape);
		if (_level != _maxLevel) {
			_NW->Draw(canvas);
			_NE->Draw(canvas);
			_SW->Draw(canvas);
			_SE->Draw(canvas);
		}
		// std::cout << "Quadtree draw end" << std::endl;
	}
=======
Quadtree::Quadtree(float x, float y, float width, float height, int level, int maxLevel) : _x(x), _y(y), _width(width), _height(height), _level(level), _maxLevel(maxLevel)
{
    // //std::cout << "Quadtree cons begin, maxlevel: " << _maxLevel << std::endl;
    _shape.setPosition(_x, _y);
	_shape.setSize(sf::Vector2f(_width, _height));
	_shape.setFillColor(sf::Color(0, 0, 0, 0));
	_shape.setOutlineThickness(1.0f);
	_shape.setOutlineColor(sf::Color(64, 128, 255));
    if (_level == _maxLevel) {
		return;
	}
	_NW = new Quadtree(_x, _y, _width / 2.0f, _height / 2.0f, _level+1, _maxLevel);
	_NE = new Quadtree(_x + _width / 2.0f, _y, _width / 2.0f, _height / 2.0f, _level+1, _maxLevel);
	_SW = new Quadtree(_x, _y + _height / 2.0f, _width / 2.0f, _height / 2.0f, _level+1, _maxLevel);
	_SE = new Quadtree(_x + _width / 2.0f, _y + _height / 2.0f, _width / 2.0f, _height / 2.0f, _level+1, _maxLevel);
    // //std::cout << "Quadtree cons end" << std::endl;

}

Quadtree::~Quadtree()
{
    // //std::cout << "Quadtree des begin" << std::endl;
    if (_level == _maxLevel)
		return;

	delete _NW;
	delete _NE;
	delete _SW;
	delete _SE;
    // //std::cout << "Quadtree des end" << std::endl;
}

void Quadtree::AddObject(Object *object)
{
    // //std::cout << "Quadtree add Object begin" << std::endl;
    if (_level == _maxLevel) {
        // //std::cout << "-----\nPushed back start: " << (*object)._id << std::endl;
		_objects.push_back(object);
        // //std::cout << "Pushed back end: " << _objects.size() << std::endl;
		return;
	}
	if (contains(_NW, object)) {
		_NW->AddObject(object);
		return;
	} else if (contains(_NE, object)) {
		_NE->AddObject(object);
		return;
	} else if (contains(_SW, object)) {
		_SW->AddObject(object);
		return;
	} else if (contains(_SE, object)) {
		_SE->AddObject(object);
		return;
	}
	if (contains(this, object)) {
		_objects.push_back(object);
	}
    // //std::cout << "Quadtree add Object end" << std::endl;
}

void Quadtree::Clear()
{
    // //std::cout << "Quadtree clear begin" << std::endl;
    if (_level == _maxLevel) {
		_objects.clear();
		return;
	} else {
		_NW->Clear();
		_NE->Clear();
		_SW->Clear();
		_SE->Clear();
	}
	if (!_objects.empty()) {
		_objects.clear();
	}
    // //std::cout << "Quadtree clear end" << std::endl;
}

bool Quadtree::contains(Quadtree *child, Object *object)
{
    // //std::cout << "Quadtree contains begin" << std::endl;
    if (object->_x < child->_x || object->_y < child->_y
    || object->_x > child->_x + child->_width  ||
	object->_y > child->_y + child->_height ||
	object->_x + object->_width < child->_x ||
	object->_y + object->_height < child->_y ||
	object->_x + object->_width > child->_x + child->_width ||
	object->_y + object->_height > child->_y + child->_height) {
        // //std::cout << "Quadtree contains end" << std::endl;
        return false;
    }
    // //std::cout << "Quadtree contains end" << std::endl;
    return true;
}

void Quadtree::Draw(sf::RenderTarget &canvas)
{
    // //std::cout << "Quadtree draw begin" << std::endl;
	std::stringstream ss;
	ss << _objects.size();
	std::string numObjectsStr = ss.str();
	canvas.draw(_shape);
	if (_level != _maxLevel) {
		_NW->Draw(canvas);
		_NE->Draw(canvas);
		_SW->Draw(canvas);
		_SE->Draw(canvas);
	}
    // //std::cout << "Quadtree draw end" << std::endl;
}

void Quadtree::detectCollision()
{
    if (_level == _maxLevel) {
        for (auto i = _objects.begin(); i != _objects.end(); i++) {
            for (auto y = _objects.begin(); y != _objects.end(); y++) {
                if ((*i) != (*y)) {
                    if ((*i)->_x < (*y)->_x + (*y)->_width
                    && (*i)->_x + (*i)->_width > (*y)->_x
                    && (*i)->_y < (*y)->_y + (*y)->_height
                    && (*i)->_y + (*i)->_height > (*y)->_y)
                        //std::cout << "Collision detected for ids: " << (*i)->_id << " and " << (*y)->_id << std::endl;
                }
            }
        }
        return;
    }
    _NE->detectCollision();
    _NW->detectCollision();
    _SE->detectCollision();
    _SW->detectCollision();
}

	void Quadtree::detectCollision()
	{
		if (_level == _maxLevel) {
			for (auto i = _objects.begin(); i != _objects.end(); i++) {
				for (auto y = _objects.begin(); y != _objects.end(); y++) {
					if ((*i) != (*y)) {
						if ((*i)->pos.x < (*y)->pos.x + (*y)->size.x
						&& (*i)->pos.x + (*i)->size.x > (*y)->pos.x
						&& (*i)->pos.y < (*y)->pos.y + (*y)->size.y
						&& (*i)->pos.y + (*i)->size.y > (*y)->pos.y)
							std::cout << "Collision detected for ids: " << (*i)->getId() << " and " << (*y)->getId() << std::endl;
							// std::cout << "Collision detected for ids: " << std::endl;
					}
				}
			}
			return;
		}
		_NE->detectCollision();
		_NW->detectCollision();
		_SE->detectCollision();
		_SW->detectCollision();
	}
}