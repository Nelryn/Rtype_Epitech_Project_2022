#include "MapError.hpp"

namespace sfge {
    MapError::MapError(std::string &msg) : _msg(msg)
    {

    }

    MapError::~MapError()
    {
    }

    const char *MapError::what()
    {
        return _msg.c_str();
    }

} //namespace sfge