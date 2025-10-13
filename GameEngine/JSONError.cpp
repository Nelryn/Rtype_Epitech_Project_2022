#include "JSONError.hpp"

namespace sfge {
    JsonError::JsonError(std::string &msg) : _msg(msg)
    {
        _msg = msg;
    }

    JsonError::~JsonError()
    {
    }

    const char *JsonError::what()
    {
        return "";
        //_msg.c_str();
    }

} //namespace sfge