#pragma once

#include <exception>
#include <string>

namespace sfge {
    class ResourcesError : public std::exception {
        public:
            ResourcesError(std::string &msg);
            ~ResourcesError();
            const char *what();

        private:
            std::string _msg;
    };
} // namespace sfge