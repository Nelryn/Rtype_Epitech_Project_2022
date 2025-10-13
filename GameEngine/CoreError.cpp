#include "Error/CoreError.hpp"

namespace sfge {
    CoreError::CoreError(std::string &msg) : _msg(msg)
    {

    }

    CoreError::~CoreError()
    {
    }

    const char *CoreError::what()
    {
        return _msg.c_str();
    }

} //namespace sfge