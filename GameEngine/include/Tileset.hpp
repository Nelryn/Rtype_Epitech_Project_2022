/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** Tileset
*/

#include <string>

struct TileS
{
    int firstG;
    int tileWidth;
    int tileHeight;
    int width;
    int height;
    int margin;
    int spacing;
    int numColumn;
    std::string name;
};

class Tileset
{
    public:
        Tileset();
        ~Tileset();
    private:
};
