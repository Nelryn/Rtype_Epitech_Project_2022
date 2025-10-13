/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** Map
*/

#include "include/Map.hpp"
#include "include/pugixml.hpp"

Map::Map()
{
}

Map::~Map()
{
}

std::string Map::stockMap(std::string const &str)
{
    _ifs.open(str);

    std::stringstream buff;
    buff << _ifs.rdbuf();
    _mapBuff = buff.str();
    _ifs.close();
    return _mapBuff;
}

void Map::read()
{
    for (auto it : _list){
        for (auto elem : it.second) {
            for (auto i : elem) {
                //std::cout << i << " ";
            }
    
        }
    }
}

void Map::parsingCsv()
{
    std::vector<std::string> mapPath = {"csvMap", "csvMap0"};
    for (auto it : mapPath)
    {
        std::string map = stockMap(it);
        std::string delimiter = ",";
        std::vector<std::string> line;
        std::vector<std::vector<std::string>> _map;
        std::string name = "";
 
        while ((_pos = map.find(delimiter)) != std::string::npos) {
            _token = map.substr(0, _pos);
            if (name.size() == 0){
                name = _token;
                map.erase(0, _pos + delimiter.length());
                continue;
            }

            map.erase(0, _pos + delimiter.length());
            line.push_back(_token);
                if (_token.find("\n") != std::string::npos){
                    _map.push_back(line);
                    line.clear();
                }
        }
        _map.push_back(line);
        _list.insert(std::pair<std::string, std::vector<std::vector<std::string>>>(name, _map));
    }
    read();
}

int main()
{
    Map map;
    map.parsingCsv();
    return 0;
}
