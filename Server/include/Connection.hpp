

#pragma once

#include <boost/asio.hpp>

class Connection
{
    public:
        Connection(unsigned char idCli, boost::asio::ip::udp::endpoint &endpoint);

        ~Connection();
        boost::asio::ip::udp::endpoint _endpoint;
        unsigned char idCli;
        boost::asio::streambuf buff;
};
