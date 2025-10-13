/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** ResourceAllocator
*/

#pragma once

#include <map>
#include <unordered_map>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class ResourceAllocator {
    public:
        ResourceAllocator() {};
        ~ResourceAllocator() {};
        std::string Add()
        {
            std::vector<std::string> containt;
            std::unordered_map<std::string, std::string> content;
            std::string str;
            int y = 0;
            std::ifstream myfile("./config.json");

            while (getline(myfile, str)) {
                if (str.find('}') == std::string::npos)
                    if (str.find('{') == std::string::npos) {
                        std::stringstream stream(str);
                        while (getline(stream, str, ':')) {
                            str.erase(remove(str.begin(), str.end(), ' '), str.end());
                            str.erase(remove(str.begin(), str.end(), '"'), str.end());
                            str.erase(remove(str.begin(), str.end(), ','), str.end());
                            containt.push_back(str);
                        }
                        stream.str("");
                    }
            }
            for (auto i = containt.begin(); i != containt.end(); i++) {
                if (y % 2 == 0) {
                    str = (*i);
                } else if (y % 2 == 1) {
                    content.insert({str, (*i)});
                }
                y++;
            }
            myfile.close();
            for (auto i = content.begin(); i != content.end(); i++) {
                auto it = resources.find((*i).first); // 1
                if (it != resources.end()) {
                    return it->first;
                }
                std::shared_ptr<T> resource = std::make_shared<T>();
                if (!resource->loadFromFile((*i).second)) // 2
                {
                    return "None";
                }
                resources.insert(
                std::make_pair((*i).first, resource));
                //std::cout << "filePath: " << (*i).first << std::endl;
            }
            return "Good";
        }
        void Remove(std::string name)
        {
            for (auto it = resources.begin(); it != resources.end(); ++it) {
                if (it->first == name) {
                    resources.erase(it->first);
                }
            }
        }
        std::shared_ptr<T> Get(std::string name)
        {
            for (auto it = resources.begin(); it != resources.end(); ++it) {
                if (it->first == name) {
                    return it->second;
                }
            }
            return nullptr;
        }
        bool Has(std::string name)
        {
            return (Get(name) != nullptr);
        }
    protected:
    private:
        std::map<std::string, std::shared_ptr<T>> resources;
};