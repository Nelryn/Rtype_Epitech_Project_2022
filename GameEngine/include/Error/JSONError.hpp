#pragma once

#include <exception>
#include <string>

namespace sfge {
    class JsonError : public std::exception {
        public:
            JsonError(std::string &msg);
            ~JsonError();
            const char *what();

        private:
            std::string _msg;
    };
} // namespace sfge