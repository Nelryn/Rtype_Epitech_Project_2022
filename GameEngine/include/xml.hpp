/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** xml
*/

#ifndef XML_HPP_
#define XML_HPP_

#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include "Factory.hpp"

#include <iostream>

namespace sfge {

    class xml
    {
        public:
            xml();
            ~xml();
            int readXML(std::string const &filepath);
        private:
    };
};

#endif /* !XML_HPP_ */
