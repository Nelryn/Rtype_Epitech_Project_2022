#include "include/Error/FactoryError.hpp"

namespace sfge {
    FactoryError::FactoryError(std::string &msg) : _msg(msg)
    {

    }

    FactoryError::~FactoryError()
    {
    }

    const char *FactoryError::what()
    {
        return _msg.c_str();
    }

} //namespace sfge

