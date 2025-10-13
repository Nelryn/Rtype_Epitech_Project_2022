#pragma once

#include <exception>
#include <string>

namespace sfge {
    class FactoryError : public std::exception {
        public:
            FactoryError(std::string &msg);
            ~FactoryError();
            const char *what();

        private:
            std::string _msg;
    };
} // namespace sfge