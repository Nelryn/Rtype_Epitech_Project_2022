#pragma once

#include <boost/asio.hpp>


class ConnectionUdp
{
public:
    ConnectionUdp();
    ~ConnectionUdp();
    boost::asio::ip::udp::endpoint _endpoint;
};
