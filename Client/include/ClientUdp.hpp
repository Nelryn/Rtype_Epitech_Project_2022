/*
** EPITECH PROJECT, 2022
** r-type
** File description:
** ClientUdp
*/

#ifndef CLIENTUDP_HPP_
#define CLIENTUDP_HPP_

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

namespace sfge {

class ClientUdp {
    public:
        ClientUdp(boost::asio::io_context &ioc, std::string addr);
        ~ClientUdp();
        void sendMsg(std::string msg);
        void receiveMsg();
        void start();

    protected:
    private:
        udp::socket _socket;
        udp::endpoint _endpoint;
        boost::array<char, 1024> _sendBuffer;
        boost::array<char, 1024> _recvBuffer;
};

}

#endif /* !CLIENTUDP_HPP_ */
