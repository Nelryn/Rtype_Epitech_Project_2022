#pragma once

#include <exception>
#include <string>

namespace sfge {
    class XmlError : public std::exception {
        public:
            XmlError(std::string &msg);
            ~XmlError();
            const char *what();

        private:
            std::string _msg;
    };
} // namespace sfge