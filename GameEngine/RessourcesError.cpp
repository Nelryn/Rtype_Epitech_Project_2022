#include "RessourcesError.hpp"

namespace sfge {
    ResourcesError::ResourcesError(std::string &msg) : _msg(msg)
    {

    }

    ResourcesError::~ResourcesError()
    {
    }

    const char *ResourcesError::what()
    {
        return _msg.c_str();
    }

} //namespace sfge