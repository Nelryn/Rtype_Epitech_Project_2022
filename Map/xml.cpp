/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** xml
*/


#include "include/xml.hpp"
using namespace pugi;
using namespace std;

xml::xml()
{
}

xml::~xml()
{
}

int xml::readXML()
{
    xml_document doc;
   
    if (!doc.load_file("map/map_t.tmx")){
        //std::cout << "failed" << std::endl;
        return -1;
    }
    xml_node tools = doc.child("map").child("objectgroup");
   
    for (xml_node_iterator it = tools.begin(); it != tools.end(); ++it)
    {
        cout << "object:";

        for (xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait)
        {
            cout << " " << ait->name() << "=" << ait->value();
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

int main()
{
    xml xml;
    xml.readXML();
    return 0;
}