#include "ParseConfig.hpp"

int main()
{
    std::string file = "../../Configuration/config_window.json";
    std::string filename = "../../Configuration/config_enemy.json";

    std::map<std::string, std::vector<std::string>> infoData;
    std::vector<std::map<std::string, std::vector<std::string>>> listData;

    sfge::ParseConfig parser(file);
    sfge::ParseConfig config(filename);

    parser.parseData();
    config.parseListData();

    infoData = parser.getInfoData();
    listData = config.getListInfoData();

    for (auto &map : infoData) {
        //std::cout << map.first << ": ";
        for (auto &vec : map.second)
            //std::cout << vec << " ";
        //std::cout << std::endl;
    }

    //std::cout << "-------------" << std::endl;

    for (auto &elem : listData) {
        for (auto &map : elem) {
            //std::cout << map.first << ": ";
            for (auto &vec : map.second)
                //std::cout << vec << " ";
        }
        //std::cout << std::endl;
    }
    return 0;
}