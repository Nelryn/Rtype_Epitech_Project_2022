
#pragma once

#include <memory>
#include <boost/asio.hpp>
//#include "Server.hpp"

class ServerClient {
    public:
        ServerClient(boost::asio::io_context &context);
        void operator=(ServerClient &client);
        ~ServerClient();
        boost::asio::ip::tcp::socket socket;
        boost::asio::streambuf buff;
};

class MessageTcp {
    public:
        MessageTcp(std::shared_ptr<ServerClient> client);
        ~MessageTcp();
        std::shared_ptr<ServerClient> _client;
        std::string message;
};