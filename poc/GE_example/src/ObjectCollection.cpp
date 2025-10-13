/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** ObjectCollection
*/

#include "../include/ObjectCollection.hpp"
#include <iostream>

ObjectCollection::ObjectCollection()
{
    //std::cout << "OC construct begin" << std::endl;
    //std::cout << "OC construct end" << std::endl;
}

ObjectCollection::~ObjectCollection()
{
}

void ObjectCollection::Add(std::shared_ptr<Object> object)
{
    //std::cout << "OC add begin" << std::endl;
    newObjects.push_back(object);
    //std::cout << "OC add end" << std::endl;
}

void ObjectCollection::Update(float deltaTime)
{
    //std::cout << "OC update begin" << std::endl;
    for(auto& o : objects) {
        o->Update(deltaTime);
    }
    //std::cout << "OC update end" << std::endl;
}

void ObjectCollection::LateUpdate(float deltaTime)
{
    //std::cout << "OC lateupdate begin" << std::endl;
    for(auto& o : objects) {
        o->LateUpdate(deltaTime);
    }
    //std::cout << "OC lateupdate end" << std::endl;
}

void ObjectCollection::Draw(Window& window)
{
    //std::cout << "OC draw begin" << std::endl;
    for(auto& o : objects) {
        o->Draw(window);
    }
    //std::cout << "OC draw end" << std::endl;
}

void ObjectCollection::ProcessNewObjects()
{
    //std::cout << "OC processnewobjects begin" << std::endl;
    if (newObjects.size() > 0) {
        for (const auto& o : newObjects) {
            o->Awake();
        }
        for (const auto& o : newObjects) {
            o->Start();
        }
        objects.assign(newObjects.begin(), newObjects.end());
        newObjects.clear();
    }
    //std::cout << "OC processnewobjects end" << std::endl;
}

void ObjectCollection::ProcessRemovals()
{
    //std::cout << "OC processremoval begin" << std::endl;
    auto objIterator = objects.begin();
    while (objIterator != objects.end()) {
        auto obj = **objIterator;
        if (obj.IsQueuedForRemoval()) {
            objIterator = objects.erase(objIterator);
        } else {
            ++objIterator;
        }
    }
    //std::cout << "OC processremoval end" << std::endl;
}