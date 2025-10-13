#include "include/Error/XmlError.hpp"

namespace sfge {
    XmlError::XmlError(std::string &msg) : _msg(msg)
    {

    }

    XmlError::~XmlError()
    {
    }

    const char *XmlError::what()
    {
        return _msg.c_str();
    }

} //namespace sfge