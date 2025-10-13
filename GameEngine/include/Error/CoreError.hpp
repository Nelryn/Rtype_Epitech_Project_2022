#pragma once

#include <exception>
#include <string>

namespace sfge {
    class CoreError : public std::exception {
        public:
            CoreError(std::string &msg);
            ~CoreError();
            const char *what();

        private:
            std::string _msg;
    };
} // namespace sfge