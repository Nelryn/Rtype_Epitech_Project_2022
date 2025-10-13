/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** ParseConfig
*/

#include "ParseConfig.hpp"
#include "JSONError.hpp"

namespace sfge {

ParseConfig::ParseConfig(std::string const &filename)
{
    this->readFile(filename);
}

ParseConfig::~ParseConfig()
{
}

void ParseConfig::readFile(std::string const &filename)
{
    try {
        boost::property_tree::read_json(filename.c_str(), _data);
        std::string err = "Couldn't load the json file : " + filename;
        JsonError error(err);
    } catch(JsonError error) {
        std::cerr << error.what() << std::endl;
    }
}

void ParseConfig::parseData()
{
    std::vector<std::string> vector;

    for (boost::property_tree::ptree::value_type &elem : _data) {
        if (elem.second.empty()) {
            vector.push_back(elem.second.data());
            _infoData.insert({elem.first, vector});
        } else {
            vector = this->dataInTab(elem.second);
            _infoData.insert({elem.first, vector});
        }
        vector.clear();
    }
}

void ParseConfig::parseListData()
{
    std::map<std::string, std::vector<std::string>> map;
    std::vector<std::string> vector;

    for (boost::property_tree::ptree::value_type &elem : _data) {
        if (elem.second.empty()) {
            vector.push_back(elem.second.data());
            map.insert({elem.first, vector});
            _listData.push_back(map);
        } else {
            for (boost::property_tree::ptree::value_type &element : elem.second) {
                if (element.first.empty()) {
                    vector = this->dataInTab(elem.second);
                    map.insert({elem.first, vector});
                    break;
                } else {
                    if (element.second.empty()) {
                        vector.push_back(element.second.data());
                        map.insert({element.first, vector});
                    } else {
                        this->dataInTab(element.second);
                        vector = this->dataInTab(element.second);
                        map.insert({element.first, vector});
                    }
                    vector.clear();
                }
            }
            _listData.push_back(map);
        }
        map.clear();
        vector.clear();
    }
}

std::vector<std::string> ParseConfig::dataInTab(boost::property_tree::ptree tree)
{
    std::vector<std::string> vector;

    for (boost::property_tree::ptree::value_type &elem : tree) {
        vector.push_back(elem.second.data());
    }
    return vector;
}

std::map<std::string, std::vector<std::string>> ParseConfig::getInfoData() const
{
    return _infoData;
}

std::vector<std::map<std::string, std::vector<std::string>>> ParseConfig::getListInfoData() const
{
    return _listData;
}

boost::property_tree::ptree ParseConfig::getAllData() const
{
    return _data;
}

}
