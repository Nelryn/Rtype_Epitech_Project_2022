/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** xml
*/


#include "include/xml.hpp"
#include "Entity.hpp"
#include "Factory.hpp"
#include "Core.hpp"
#include "EntityManager.hpp"
#include "include/Error/XmlError.hpp"

using namespace pugi;
using namespace std;


namespace sfge {
    xml::xml()
    {
    }

    xml::~xml()
    {
    }

    int xml::readXML(const std::string &filepath)
    {
        xml_document doc;

        if (!doc.load_file(filepath.c_str())) {
            //std::cout << "failed" << std::endl;
            return -1;
        }
        xml_node tools = doc.child("map").child("objectgroup");
    
        for (xml_node_iterator it = tools.begin(); it != tools.end(); ++it)
        {
            Entity* entity = Core::getInstance()->factory->createEntity("Wall");
            try {
                entity->pos.x = it->attribute("x").as_float();
                entity->pos.y = it->attribute("y").as_float();
                entity->size.x = it->attribute("width").as_float();
                entity->size.y = it->attribute("height").as_float();
            } catch (XmlError error) {
                std::cerr << error.what() << std::endl;
                exit(84);
            }
        }

        return 0;
    }
}