#pragma once

#include <exception>
#include <string>

namespace sfge {
    class MapError : public std::exception {
        public:
            MapError(std::string &msg);
            ~MapError();
            const char *what();

        private:
            std::string _msg;
    };
} // namespace sfge