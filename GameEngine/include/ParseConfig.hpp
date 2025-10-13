/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** ParseConfig
*/

#ifndef PARSECONFIG_HPP_
#define PARSECONFIG_HPP_

#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <vector>
#include <map>

namespace sfge {

class ParseConfig {
    public:
        /**
         * @brief  
         * @note   constructor
         * @param  &filename: path name - std::string
         * @retval 
         */
        ParseConfig(std::string const &filename);
        /**
         * @brief  
         * @note   destructor
         * @retval 
         */
        ~ParseConfig();

        /**
         * @brief  
         * @note   read data in file
         * @param  &filename: path name - std::string
         * @retval None
         */
        void readFile(std::string const &filename);
        /**
         * @brief  
         * @note   parse and stock data
         * @retval None
         */
        void parseData();
        /**
         * @brief  
         * @note   parse and stock data in list
         * @retval None
         */
        void parseListData();
        /**
         * @brief  
         * @note   get info
         * @retval std::map<std::string, std::vector<std::string>>
         */
        std::map<std::string, std::vector<std::string>> getInfoData() const;
        /**
         * @brief  
         * @note   get info list
         * @retval std::vector<std::map<std::string, std::vector<std::string>>>
         */
        std::vector<std::map<std::string, std::vector<std::string>>> getListInfoData() const;
        /**
         * @brief  
         * @note   parse data tab
         * @param  tree: data tab - boost::property_tree::ptree
         * @retval std::vector<std::string>
         */
        std::vector<std::string> dataInTab(boost::property_tree::ptree tree);
        /**
         * @brief  
         * @note   get all data
         * @retval boost::property_tree::ptree
         */
        boost::property_tree::ptree getAllData() const;
    protected:
    private:
        /**
         * @brief  
         * @note   all data in file
         * @retval boost::property_tree::ptree
         */
        boost::property_tree::ptree _data;
        /**
         * @brief  
         * @note   information
         * @retval std::map<std::string, std::vector<std::string>>
         */
        std::map<std::string, std::vector<std::string>> _infoData;
        /**
         * @brief  
         * @note   list information
         * @retval std::vector<std::map<std::string, std::vector<std::string>>>
         */
        std::vector<std::map<std::string, std::vector<std::string>>> _listData;
};
}

#endif /* !PARSECONFIG_HPP_ */
