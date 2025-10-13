/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** Map
*/

#ifndef Map_HPP_
#define Map_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>

class Map {
    public:
        Map();
        ~Map();
        std::string stockMap(std::string const &str);
        void parsingCsv();
        void read();

    protected:
    private:
        std::string _mapBuff;
        std::ifstream _ifs;
        std::string _line;
        size_t _pos = 0;
        std::string _token;
        std::unordered_map<std::string, std::vector<std::vector<std::string>>> _list;
};

#endif /* !Map_HPP_ */
